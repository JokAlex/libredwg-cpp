#include <libredwg_cpp/document.hpp>
#include <libredwg_cpp/error.hpp>

#include "bits.h"
#include <dwg.h>

extern "C" {
int dwg_write_dxf(Bit_Chain *dat, Dwg_Data *dwg);
}

namespace {
struct FilePtrDeleter final {
  void operator()(FILE *file) const noexcept { fclose(file); }
};
} // namespace

namespace libredwg {

struct Document::Impl final : Dwg_Data {};

void Document::ImplDeleter::operator()(Impl *impl) const noexcept {
  dwg_free(impl);
}

Document::~Document() = default;

Document Document::open(const std::string &path) {
  ImplPtr impl(new Impl);
  memset(impl.get(), 0, sizeof(Impl));

  auto error = dwg_read_file(path.c_str(), impl.get());
  switch (error) {
  case DWG_ERR_CLASSESNOTFOUND:
    throw ParseError("Parsing error: classed not found");
  case DWG_ERR_SECTIONNOTFOUND:
    throw ParseError("Parsing error: section not found");
  case DWG_ERR_PAGENOTFOUND:
    throw ParseError("Parsing error: page not found");
  case DWG_ERR_INTERNALERROR:
    throw InternalError("An internal error occured");
  case DWG_ERR_INVALIDDWG:
    throw ValidationError("DWG file is invalid");
  case DWG_ERR_IOERROR:
    throw IOError("Cannot read the given DWG file");
  case DWG_ERR_OUTOFMEM:
    throw MemoryError("Out of memory during DWG file reading");
  }
  return Document(std::move(impl));
}

void Document::writeDxf(const std::string &path) const {
  Bit_Chain dat = {0};
  dat.version = mImpl->header.version;
  dat.from_version = mImpl->header.from_version;

  std::unique_ptr<FILE, FilePtrDeleter> file(fopen(path.c_str(), "wb"));
  dat.fh = file.get();
  if (dat.fh == NULL) {
    throw IOError("Cannot open DXF file for writing");
  }
  auto write_error = dwg_write_dxf(&dat, mImpl.get());
  switch (write_error) {
  case DWG_ERR_INTERNALERROR:
    throw InternalError("An internal error occured");
  case DWG_ERR_IOERROR:
    throw IOError("Cannot write to the given DXF file");
  case DWG_ERR_OUTOFMEM:
    throw MemoryError("Out of memory during DXF file writing");
  }
}

Version Document::version() const noexcept {
  return static_cast<Version>(mImpl->header.version);
}

Document::Document(ImplPtr impl) : mImpl(std::move(impl)) {}

} // namespace libredwg

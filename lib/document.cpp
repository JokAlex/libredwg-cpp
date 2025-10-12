#include <libredwg_cpp/document.hpp>

namespace libredwg {

struct Document::Impl final {};

void Document::ImplDeleter::operator()(Impl *impl) const { delete impl; }

Document::~Document() = default;

Document Document::open(std::string_view path) { return Document(nullptr); }

void Document::writeDxf(std::string_view path, const SaveOptions &opts) const {}

Document::Document(ImplPtr impl) {}

} // namespace libredwg

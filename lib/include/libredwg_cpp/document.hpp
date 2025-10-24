#pragma once

#include <memory>
#include <string>

#include <libredwg_cpp/version.hpp>
#include <libredwg_cpp_export_shared.hpp>

namespace libredwg {

/**
 * This class represents the DWG document.
 */
class LIBREDWG_CPP_EXPORT Document final {
public:
  Document(Document&&) noexcept = default;
  ~Document();

  Document& operator = (Document&&) noexcept = default;

  /**
   * Opens an existing DWG file specified by path.
   * \param path path to the DWG file.
   * \returns new document, linked to the given DWG file.
   */
  static Document open(const std::string& path);

  /**
   * Converts document to DXF format and writes it to the file specified by path. If
   * file does not exist, this method will create a new one.
   * \param path path to the DXF file.
   */
  void writeDxf(const std::string& path) const;

  /**
   * Returns version of the document.
   */
  Version version() const noexcept;

private:
  class Impl;

  struct ImplDeleter final {
    void operator()(Impl *impl) const noexcept;
  };

  using ImplPtr = std::unique_ptr<Impl, ImplDeleter>;

private:
  Document(ImplPtr impl);

private:
  ImplPtr mImpl;
};

} // namespace libredwg

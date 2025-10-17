#pragma once

#include <memory>
#include <string>

#include <libredwg_cpp/save_options.hpp>
#include <libredwg_cpp/version.hpp>
#include <libredwg_cpp_export_shared.hpp>

namespace libredwg {

class LIBREDWG_CPP_EXPORT Document final {
public:
  ~Document();

  static Document open(const std::string& path);

  void writeDxf(const std::string& path, const SaveOptions &opts) const;

  Version getVersion() const noexcept;

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

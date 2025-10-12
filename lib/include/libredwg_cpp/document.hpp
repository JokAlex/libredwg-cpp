#pragma once

#include <memory>
#include <string>

#include <libredwg_cpp/save_options.hpp>
#include <libredwg_cpp_export_shared.hpp>

namespace libredwg {

class LIBREDWG_CPP_EXPORT Document final {
public:
  ~Document();

  static Document open(std::string_view path);

  void writeDxf(std::string_view path, const SaveOptions &opts) const;

private:
  class Impl;

  struct ImplDeleter final {
    void operator()(Impl *impl) const;
  };

  using ImplPtr = std::unique_ptr<Impl, ImplDeleter>;

private:
  Document(ImplPtr impl);

private:
  ImplPtr mImpl;
};

} // namespace libredwg

#pragma once

#include <stdexcept>

#include <libredwg_cpp_export_shared.hpp>

namespace libredwg {

struct LIBREDWG_CPP_EXPORT Error : std::runtime_error {
  using std::runtime_error::runtime_error;
};

struct LIBREDWG_CPP_EXPORT IOError : Error {
  using Error::Error;
};

struct LIBREDWG_CPP_EXPORT ParseError : Error {
  using Error::Error;
};

struct LIBREDWG_CPP_EXPORT UnsupportedError : Error {
  using Error::Error;
};

struct LIBREDWG_CPP_EXPORT ValidationError : Error {
  using Error::Error;
};

struct LIBREDWG_CPP_EXPORT MemoryError : Error {
  using Error::Error;
};

struct LIBREDWG_CPP_EXPORT InternalError : Error {
  using Error::Error;
};

} // namespace libredwg

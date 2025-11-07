#pragma once

#include <stdexcept>

#include <libredwg_cpp_export_shared.hpp>

namespace libredwg {

/**
 * Represents a general error in the libredwg_cpp library.
 */
struct LIBREDWG_CPP_EXPORT Error : std::runtime_error {
  using std::runtime_error::runtime_error;
};

/**
 * Represents an input-output error, for example if file not exists.
 */
struct LIBREDWG_CPP_EXPORT IOError : Error {
  using Error::Error;
};

/**
 * Represents an error occurring during the parsing DWG file.
 */
struct LIBREDWG_CPP_EXPORT ParseError : Error {
  using Error::Error;
};

/**
 * Represents an error occurring if DWG file contains unsupported features.
 */
struct LIBREDWG_CPP_EXPORT UnsupportedError : Error {
  using Error::Error;
};

/**
 * Represents an error occurring if DWG file is not valid.
 */
struct LIBREDWG_CPP_EXPORT ValidationError : Error {
  using Error::Error;
};

/**
 * Represents an internal error in the libredwg_cpp library.
 */
struct LIBREDWG_CPP_EXPORT InternalError : Error {
  using Error::Error;
};

} // namespace libredwg

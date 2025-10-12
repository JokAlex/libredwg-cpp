#pragma once

#include <libredwg_cpp/version.hpp>

namespace libredwg {

struct SaveOptions {
  Version targetVersion = Version::R2000;
  bool minimal = false;
  bool overwrite = false;
};

} // namespace libredwg

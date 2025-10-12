#pragma once

#include <cstdint>

namespace libredwg {

enum class Version : std::uint32_t {
  Invalid = 0,
  R12,
  R14,
  R2000,
  R2004,
  R2007,
  R2010,
  R2013,
  R2018,
};

}

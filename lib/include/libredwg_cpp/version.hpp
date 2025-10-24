#pragma once

#include <cstdint>
#include <dwg.h>

namespace libredwg {

/**
 * Version of DWG document. Corresponds to the LibreDWG enum Dwg_Version_Type.
 */
enum class Version : std::uint32_t {
  INVALID   = Dwg_Version_Type::R_INVALID,
  R_1_1     = Dwg_Version_Type::R_1_1,
  R_1_2     = Dwg_Version_Type::R_1_2,
  R_1_3     = Dwg_Version_Type::R_1_3,
  R_1_4     = Dwg_Version_Type::R_1_4,
  R_2_0b    = Dwg_Version_Type::R_2_0b,
  R_2_0     = Dwg_Version_Type::R_2_0,
  R_2_10    = Dwg_Version_Type::R_2_10,
  R_2_21    = Dwg_Version_Type::R_2_21,
  R_2_22    = Dwg_Version_Type::R_2_22,
  R_2_4     = Dwg_Version_Type::R_2_4,
  R_2_5     = Dwg_Version_Type::R_2_5,
  R_2_6     = Dwg_Version_Type::R_2_6,
  R_9       = Dwg_Version_Type::R_9,
  R_9c1     = Dwg_Version_Type::R_9c1,
  R_10      = Dwg_Version_Type::R_10,
  R_11b1    = Dwg_Version_Type::R_11b1,
  R_11b2    = Dwg_Version_Type::R_11b2,
  R_11      = Dwg_Version_Type::R_11,
  R_12      = Dwg_Version_Type::R_12,
  R_13b1    = Dwg_Version_Type::R_13b1,
  R_13b2    = Dwg_Version_Type::R_13b2,
  R_13      = Dwg_Version_Type::R_13,
  R_13c3    = Dwg_Version_Type::R_13c3,
  R_14      = Dwg_Version_Type::R_14,
  R_2000b   = Dwg_Version_Type::R_2000b,
  R_2000    = Dwg_Version_Type::R_2000,
  R_2000i   = Dwg_Version_Type::R_2000i,
  R_2002    = Dwg_Version_Type::R_2002,
  R_2004a   = Dwg_Version_Type::R_2004a,
  R_2004b   = Dwg_Version_Type::R_2004b,
  R_2004c   = Dwg_Version_Type::R_2004c,
  R_2004    = Dwg_Version_Type::R_2004,
  R_2007a   = Dwg_Version_Type::R_2007a,
  R_2007b   = Dwg_Version_Type::R_2007b,
  R_2007    = Dwg_Version_Type::R_2007,
  R_2010b   = Dwg_Version_Type::R_2010b,
  R_2010    = Dwg_Version_Type::R_2010,
  R_2013b   = Dwg_Version_Type::R_2013b,
  R_2013    = Dwg_Version_Type::R_2013,
  R_2018b   = Dwg_Version_Type::R_2018b,
  R_2018    = Dwg_Version_Type::R_2018,
  R_2022b   = Dwg_Version_Type::R_2022b,
  R_AFTER   = Dwg_Version_Type::R_AFTER,
};

}

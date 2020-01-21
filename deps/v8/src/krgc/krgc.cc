#include "src/krgc/krgc.h"

// last 2 bits are the instruction
const int krgc::loc_shift = 2;
const int krgc::insn_mask = 0x03;

const int krgc::flag = 0;
//const int krgc::flag = (static_cast<int>(krgc::location::LdaKeyedProperty) << krgc::loc_shift) | static_cast<int>(krgc::instruction::rdtscp);
//const int krgc::flag = (static_cast<int>(krgc::location::LdaKeyedProperty) << krgc::loc_shift) | static_cast<int>(krgc::instruction::rdpmc);
//const int krgc::flag = (static_cast<int>(krgc::location::overhead) << krgc::loc_shift) | static_cast<int>(krgc::instruction::rdpmc);

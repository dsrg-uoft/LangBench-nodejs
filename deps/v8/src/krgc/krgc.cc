#include "src/krgc/krgc.h"
#include <cstdio>

// last 2 bits are the instruction
const int krgc::loc_shift = 2;
const int krgc::insn_mask = 0x03;

const int krgc::int_flag = 0;
//const int krgc::int_flag = (static_cast<int>(krgc::location::LdaKeyedProperty) << krgc::loc_shift) | static_cast<int>(krgc::instruction::rdtscp);
//const int krgc::int_flag = (static_cast<int>(krgc::location::LdaKeyedProperty) << krgc::loc_shift) | static_cast<int>(krgc::instruction::rdpmc);
//const int krgc::int_flag = (static_cast<int>(krgc::location::overhead) << krgc::loc_shift) | static_cast<int>(krgc::instruction::rdpmc);

uint32_t operator | (krgc::check lhs, krgc::check rhs) {
  using T = std::underlying_type_t <krgc::check>;
  return static_cast<T>(lhs) | static_cast<T>(rhs);
}

uint32_t operator | (uint32_t lhs, krgc::check rhs) {
  using T = std::underlying_type_t<krgc::check>;
  return lhs | static_cast<T>(rhs);
}

const uint32_t krgc::jit_flag = static_cast<uint32_t>(krgc::check::none);
//const uint32_t krgc::jit_flag = static_cast<uint32_t>(krgc::check::smi);
//const uint32_t krgc::jit_flag = static_cast<uint32_t>(krgc::check::shape);
//const uint32_t krgc::jit_flag = static_cast<uint32_t>(krgc::check::array_length);
//const uint32_t krgc::jit_flag = static_cast<uint32_t>(krgc::check::array_hole);
//const uint32_t krgc::jit_flag = krgc::check::smi | krgc::check::shape | krgc::check::array_length | krgc::check::array_hole;

static thread_local bool skrilla = false;

void krgc::make_rich(bool b) {
	//printf("[hottub3] cash money records %d\n", b);
	skrilla = b;
}

bool krgc::has_money() {
	return skrilla;
}

#include "src/krgc/krgc.h"
#include <cstdio>
#include "src/utils/allocation.h"
#include "src/utils/memcopy.h"

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

//const uint32_t krgc::jit_flag = static_cast<uint32_t>(krgc::check::none);
//const uint32_t krgc::jit_flag = static_cast<uint32_t>(krgc::check::smi);
//const uint32_t krgc::jit_flag = static_cast<uint32_t>(krgc::check::shape);
//const uint32_t krgc::jit_flag = static_cast<uint32_t>(krgc::check::array_length);
//const uint32_t krgc::jit_flag = static_cast<uint32_t>(krgc::check::array_hole);
const uint32_t krgc::jit_flag = krgc::check::smi | krgc::check::shape | krgc::check::array_length | krgc::check::array_hole;

static thread_local bool skrilla = false;

void krgc::make_rich(bool b) {
	//printf("[hottub3] cash money records %d\n", b);
	skrilla = b;
}

bool krgc::has_money() {
	return skrilla;
}

static std::vector<const char*> bank;

void krgc::count_cash(const char* function) {
  for (const char* filter : bank) {
    if (strcmp(function, filter) == 0) {
      // printf("[hottub3] CreateGraph %s\n", function);
      krgc::make_rich(true);
    }
  }
}

void krgc::make_bank(const char* functions) {
  if (functions == nullptr) {
    return;
  }
  const char* start = functions;
  const char* end = functions;

  auto get_name = [](const char* start, const char* end) {
    size_t n = end - start;
    char* func = v8::internal::NewArray<char>(n + 1);
    v8::internal::MemCopy(func, start, n);
    func[n] = '\0';
    bank.push_back(func);
  };

  for (; *end != '\0'; end++) {
    if (*end == ',') {
      get_name(start, end);
      start = end + 1;
    }
  }
  if (start != end) {
    get_name(start, end);
  }
}

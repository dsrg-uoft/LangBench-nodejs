#ifndef KRGC_H_
#define KRGC_H_

#include <cstdint>
#include <type_traits>

class krgc {
 public:
  static const int loc_shift;
  static const int insn_mask;
  static const int int_flag;
  static const uint32_t jit_flag;

  enum class location : int {
    unused = 0,
    overhead = 1 << 0,
    LdaKeyedProperty = 1 << 1,
  };

  enum class instruction {
    unused = 0,
    rdtscp = 1 << 0,
    rdpmc = 1 << 1,
  };

  enum class check : uint32_t {
    none = 0,
    smi = 1 << 0,
    shape = 1 << 1,
    array_length = 1 << 2,
    array_hole = 1 << 3,
  };

  static location loc() { return static_cast<krgc::location>(krgc::int_flag >> krgc::loc_shift); };
  static instruction insn() { return static_cast<krgc::instruction>(krgc::int_flag & krgc::insn_mask); }

  static void make_rich(bool);
  static bool has_money();
  static bool skip_check(check c) { return krgc::jit_flag & static_cast<uint32_t>(c); }
};

#endif  // KRGC_H_

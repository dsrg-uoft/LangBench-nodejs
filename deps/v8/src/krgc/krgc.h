#ifndef KRGC_H_
#define KRGC_H_

class krgc {
 public:
  static const int loc_shift;
  static const int insn_mask;
  static const int flag;

  enum class location : int {
    unused = 0,
    overhead,
    LdaKeyedProperty };

  enum class instruction {
    unused = 0,
    rdtscp,
    rdpmc };

  static location loc() { return static_cast<location>(krgc::flag >> krgc::loc_shift); };
  static instruction insn() { return static_cast<krgc::instruction>(krgc::flag & krgc::insn_mask); }
};

#endif  // KRGC_H_

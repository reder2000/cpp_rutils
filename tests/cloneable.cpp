#include "stdafx.h"
#include "cloneable.h"
#include "shared_ptr.h"


class u_concrete : public UniquePtrCloneableBase<u_concrete>
{
 protected:
  virtual u_concrete *clone_impl() const { return new u_concrete; }
};

class s_concrete : public SharedPtrCloneableBase<s_concrete>
{
 protected:
  virtual s_concrete *clone_impl() const { return new s_concrete; }
};

TEST(cpp_rutils,cloneable)
{
  u_concrete object;
  auto       u_cloned = object.clone();
  static_assert(std::is_same_v<decltype(u_cloned), up<u_concrete>>);
  s_concrete object1;
  auto       s_cloned = object1.clone();
  static_assert(std::is_same_v<decltype(s_cloned), sp<s_concrete>>);
}
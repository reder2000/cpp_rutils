#include <shared_ptr.h>


TEST(cpp_rutils,shared_ptr)
{
  std::shared_ptr<int> sp1(new int{2});
  auto                 sp2 = sp<int>(new int{2});
  EXPECT_TRUE(*sp1 == *sp2);
  auto sp3 = make_sp_copy<int>(2.);
  EXPECT_TRUE(*sp1 == *sp3);
}

TEST(cpp_rutils,shared_ptr_v)
{
  using V = std::vector<int>;
  V                  v1{1, 2};
  std::shared_ptr<V> sp1(new V{1, 2});
  auto               sp2 = sp<V>(new V{1, 2});
  EXPECT_TRUE(*sp1 == *sp2);
  auto sp3 = make_sp_move<V>(v1);
  EXPECT_TRUE(*sp1 == *sp3);
  EXPECT_TRUE(v1.empty());
  auto spc1 = new_spc(1);
  auto spc2 = m_sp<V>(V{1, 2, 3});
}

TEST(cpp_rutils,tmp_sp)
{
  using V = std::vector<int>;
  V    v{1, 2};
  auto sv  = temp_sp(v);
  (*sv)[0] = 2;
  EXPECT_TRUE(v[0] == 2);
  const V& vv  = v;
  auto     sv2 = temp_sp(vv);
  static_assert(std::is_same_v<decltype(sv2)::element_type, const V>);
}

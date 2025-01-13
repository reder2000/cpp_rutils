#include "stdafx.h"
#include <shared_shared_ptr.h>
#include <shared_ptr.h>

// shared pointer of shared_pointer (why?)
template <class _Ty>
using spsp = std::shared_ptr<std::shared_ptr<_Ty>>;

template <class _Ty>
using spspc = std::shared_ptr<std::shared_ptr<const _Ty>>;

template <typename T, typename... Args>
spsp<T> m_spsp(Args&&... args)
{
	return std::make_shared< std::shared_ptr<T> >(std::make_shared<T>(T{ std::forward<Args>(args)... }));
}

TEST(cpp_rutils,shared_shared_ptr)
{
    auto s1 = m_spsp<int>(1);
    auto s2 = s1;
    **s2 = 2;
    EXPECT_TRUE(**s1 == 2);
    *s2 = m_sp<int>(3);
    EXPECT_TRUE(**s1 == 3);
}

//TEST(cpp_rutils,shared_ptr_v", "[enum][hide]")
//{
//    using V = std::vector<int>;
//    V v1{ 1,2 };
//    std::shared_ptr<V> sp1(new V{ 1,2 });
//    auto sp2 = sp<V>(new V{ 1,2 });
//    EXPECT_TRUE(*sp1 == *sp2);
//    auto sp3 = make_sp_move<V>(v1);
//    EXPECT_TRUE(*sp1 == *sp3);
//    EXPECT_TRUE(v1.empty());
//    auto spc1 = new_spc(1);
//    auto spc2 = m_sp<V>(V{ 1, 2 , 3 });
//}
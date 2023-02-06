#include <catch2/catch_test_macros.hpp>
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

TEST_CASE("shared_shared_ptr", "[enum][hide]")
{
    auto s1 = m_spsp<int>(1);
    auto s2 = s1;
    **s2 = 2;
    CHECK(**s1 == 2);
    *s2 = m_sp<int>(3);
    CHECK(**s1 == 3);
}

//TEST_CASE("shared_ptr_v", "[enum][hide]")
//{
//    using V = std::vector<int>;
//    V v1{ 1,2 };
//    std::shared_ptr<V> sp1(new V{ 1,2 });
//    auto sp2 = sp<V>(new V{ 1,2 });
//    CHECK(*sp1 == *sp2);
//    auto sp3 = make_sp_move<V>(v1);
//    CHECK(*sp1 == *sp3);
//    CHECK(v1.empty());
//    auto spc1 = new_spc(1);
//    auto spc2 = m_sp<V>(V{ 1, 2 , 3 });
//}
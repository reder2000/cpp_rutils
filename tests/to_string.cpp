#include <catch.hpp>
#include <to_string.h>

#include <sstream>
#include <string>
#include <fmt/format.h>
#include <variant>

//void f() {
//    int i;
//    std::string s ( 100 ); 
//}
//template<class T>
//std::string optionalToString(T* obj)
//{
//    constexpr bool has_toString = requires(const T & t) {
//        t.toString();
//    };
//
//    if constexpr (has_toString)
//        return obj->toString();
//    else
//        return "toString not defined";
//}

//template<typename T>
//concept has_builtin = requires {  std::convertible_to<T,const char*>;  };

template<typename T>
inline constexpr bool has_stdstring_v = std::is_convertible_v<T, std::string>;


// See http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4502.pdf.
template <typename...>
using void_t = void;

// Primary template handles all types not supporting the operation.
template <typename, template <typename> class, typename = void_t<>>
struct detect : std::false_type {};

// Specialization recognizes/validates only types supporting the archetype.
template <typename T, template <typename> class Op>
struct detect<T, Op, void_t<Op<T>>> : std::true_type {};

//// Archetypal expression for assignment operation.
//template <typename T>
////using assign_t = decltype(std::declval<T&>() = std::declval<T const&>())
//using has_fmt_t = decltype(fmt::format("{}", std::declval<T>()));
//
//// Trait corresponding to that archetype.
//template <typename T>
//inline constexpr bool has_fmt_v = detect<T, has_fmt_t>::value;

template <typename T>
inline constexpr bool has_fmt_v = fmt::formattable<T>();

//template<typename T>
//concept has_fmt = requires { fmt::format("{}", T{});  };

//template<typename T>
//inline constexpr bool has_fmt_v = has_fmt<T> 

struct A { int i; };

//template <class T>
//void f() {
//    T a;
//    fmt::format("{}", a);
//}

//void g() {
//    f<A>();
//}
static_assert(has_fmt_v<int>);

/*

template<typename T>
concept has_sstream = requires { std::ostringstream() << T{}; };

static_assert(has_stdstring_v<const int*> == false);
//static_assert(has_fmt_v<const int*> == false);

template <typename T>
std::string to_string(const T& v) {


    //constexpr bool has_builtin = requires(const T & t) {
    //    [&]() {const char* c = t; };
    //};
    //constexpr bool has_stdstring = requires(const T & t) {
    //    [&]() {std::string c = t; };
    //};
    //constexpr bool has_fmt= requires(const T & t) {
    //    fmt::format("{}", t);
    //};
    //constexpr bool has_sstream = requires(const T & t) {
    //    [&]() {std::ostringstream  ss; ss << t; };
    //};
    bool constexpr is_pointer_to_non_void = std::is_pointer_v<T> && ! std::is_void_v< std::decay_t<std::remove_pointer_t<T>>>;
    
    static_assert( (!is_pointer_to_non_void) || has_stdstring<T>, "must be implemented");

    bool constexpr has_to_string = has_stdstring<T> || has_fmt<T> || has_sstream<T>;
    static_assert(has_to_string, "must be implemented");

    if constexpr (has_stdstring<T>) { return std::string(v); }
        else {
            if constexpr ( has_fmt<T>) { return fmt::format("{}", v).c_str(); }
            else {
                if constexpr (has_sstream<T>) { std::ostringstream  ss; ss << v; return ss.str().c_str(); }
            else {
                static_assert(false, "must be implemented");
                }
            }
        }
}

template <class... T>
std::string to_string(const std::variant<T...>& v) {
    return std::visit([](auto&& a) {return to_string(a); }, v);
};

#include <catch.hpp>
#include <iostream>
#include <name.h>

enum class toto {
    red = 0
};

TEST_CASE("to_string", "[to_string][hide]")
{
    int i = 10;
    CHECK(to_string(i) == "10");
    void* v = (void*)0xF010;
    CHECK(to_string(v) == "0xf010");
    std::variant<int, const char*> vic = 12;
    CHECK(to_string(vic) == "12");
    vic = "abcd";
    CHECK(to_string(vic) == "abcd");
    //using T = void*;
    //using TT = std::decay_t<std::remove_pointer_t<T>>;
    //std::cout << type_name<TT>() << std::endl;
    //bool constexpr is_pointer_to_non_void = std::is_pointer_v<T> && !std::is_void_v< std::decay<std::remove_pointer<T>>>;
    //std::cout << "toto" << to_string(t) << std::endl;
}

*/
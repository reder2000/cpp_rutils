#include <catch2/catch_test_macros.hpp>
#include <enum.h>
#include <string_literal.h>
#include <always_false.h>
#include <require.h>
#include <optional>

#define DataType_tuple (close,\
open,\
high,\
low,\
mid,\
vwap\
)

//enum class DataType { close, open, high, low, mid, vwap };
//using DataType_tuple_sl = tuple_sl< "close", "open", "high", "low", "mid", "vwap" >;
//template <> inline std::string_view enum_to_string<DataType>(DataType value) { size_t i = static_cast <size_t>(static_cast<std::underlying_type_t<DataType>>(value)); return tuple_sl_get_i<DataType_tuple_sl>(i); };
//template <> inline DataType string_to_enum(std::string_view s) { return static_cast<DataType>(tuple_sl_index_s<DataType_tuple_sl>(s)); }
//template <> inline std::string to_string<DataType>(const DataType& value) { return std::string(enum_to_string(value)); }
//template <>struct fmt::formatter<DataType> : formatter<std::string> { template <typename FormatContext> auto format(DataType v, FormatContext& ctx) { auto s = ::to_string(v); return formatter<std::string>::format(s, ctx); } };


EMIT_ENUM_CLASS(DataType);

////using DataType_tuple_sl = tuple_sl<"close", "open", "high", "low", "mid", "vwap">;
//
//template <DataType d>
//constexpr const char* enum_to_cstring() {
//	return tuple_sl_get<static_cast<size_t>(d), DataType_tuple_sl>.value;
//}
//
//template <typename T, StringLiteral S>
//struct cstring_to_enum_s {
// static_assert(	always_false_v<T> );
//};
//
//template <StringLiteral S>
//struct cstring_to_enum_s<DataType,S> {
//	static constexpr DataType value = static_cast<DataType>(tuple_sl_index<S, DataType_tuple_sl>);
//};
//
//template <typename T, StringLiteral S>
//constexpr T cstring_to_enum = cstring_to_enum_s<T,S>::value;
//
//
//// fun but useless
//template <typename Fun, typename Cdn, typename T>
//std::optional<std::invoke_result_t<Fun, const std::string&>> apply_if(Fun fun, Cdn cdn, T)
//{
//	return std::nullopt;
//}
//
////template <typename Fun, typename Cdn, StringLiteral Head>
////std::optional<std::invoke_result_t<Fun, const std::string&>> apply_if(Fun fun, Cdn cdn, tuple_sl<Head>)
////{
////	if (cdn(Head.value)) return fun(Head.value);
////	return std::nullopt;
////}
//
//
//template <typename Fun, typename Cdn, StringLiteral Head, StringLiteral ...Tail>
//std::optional<std::invoke_result_t<Fun, const std::string&>> apply_if(Fun fun, Cdn cdn, tuple_sl<Head, Tail...>)
//{
//	if (cdn(Head.value)) return fun(Head.value);
//	return apply_if<Fun, Cdn, Tail...>(fun, cdn, tuple_sl<Tail...>{});
//}
//
//void test_apply(const std::string & s)
//{
//	auto cdn = [&s](const std::string&o) {return s == o; };
//	auto fun = [](const std::string&o) {return o.size(); };
//	auto t = apply_if(fun, cdn, DataType_tuple_sl{});
//
//}
//
//namespace detail {
//	template <size_t I, typename Cdn, typename T>
//	size_t index_if(Cdn cdn, T)
//	{
//		return std::string::npos;
//	}
//
//	//template <size_t I, typename Cdn, StringLiteral Head>
//	//size_t index_if(Cdn cdn, tuple_sl<Head>)
//	//{
//	//	if (cdn(Head.value)) return I;
//	//	return std::string::npos;
//	//}
//
//
//	template <size_t I, typename Cdn, StringLiteral Head, StringLiteral ...Tail>
//	size_t index_if(Cdn cdn, tuple_sl<Head, Tail...>)
//	{
//		if (cdn(Head.value)) return I;
//		return index_if<I + 1, Cdn, Tail...>(cdn, tuple_sl<Tail...>{});
//	}
//}
//
//template <typename Cdn, StringLiteral... S>
//size_t index_if(Cdn cdn, tuple_sl<S...> s)
//{
//	return detail::index_if<0, Cdn>(cdn,s);
//}
//
//template <typename E>
//E dstring_to_enum(std::string_view s)
//{
//	static_assert(always_false_v<E>);
//}
//
//
//template <>
//DataType dstring_to_enum(std::string_view s)
//{
//	auto cdn = [&s](auto&& o)
//	{
//		//std::cout << s << " " << o << "\n";
//		return s == o;
//	};
//	size_t i = index_if(cdn, DataType_tuple_sl{});
//	MREQUIRE(i != std::string::npos, "{} is not a valid enum", s);
//	return static_cast<DataType>(i);
//
//}


TEST_CASE("enum string", "[enum][hide]")
{
	const DataType toto(DataType::high);
	CHECK(enum_to_string(toto) == std::string("high"));
	CHECK(to_string(toto) == "high");
	CHECK(string_to_enum< DataType>("low") == DataType::low);
	// test fmt::format
	CHECK(fmt::format("{}", toto) == "high");
	//CHECK(enum_to_cstring<DataType::low>()==std::string("low"));
	//auto t = enum_to_cstring<DataType::high>();
	//auto d = cstring_to_enum< DataType, "high">;
	//CHECK(d == DataType::high);
	//d = dstring_to_enum<DataType>("vwap");
	//CHECK(d == DataType::vwap);
	//CHECK_THROWS(dstring_to_enum<DataType>("High"));
	
}

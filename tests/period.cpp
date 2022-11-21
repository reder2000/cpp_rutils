#include <catch2/catch_test_macros.hpp>
#include "period.h"
#include "date.h"


TEST_CASE("period", "[period][hide]")
{
	Date d = make_date(2022, 3, 30);
	Period p(11, TimeUnit::Months);
	Date res = d + p;
	fmt::print("date {} + {} = {}\n", d, p, res);
}

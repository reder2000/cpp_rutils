#include "period.h"
#include "date.h"


TEST(cpp_rutils,period)
{
	Date d = make_date(2022, 3, 30);
	Period p(11, TimeUnit::Months);
	Date res = d + p;
	std__print("date {} + {} = {}\n", d, p, res);
}

#include <catch2/catch_test_macros.hpp>
#include <scoped_timer.h>

#include <thread>

int sleep_for(int ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	return ms;
}

TEST_CASE("scoped timer", "[enum][hide]")
{
	{
		ScopedTimer sc;
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		voidTIMEIT(std::this_thread::sleep_for(std::chrono::milliseconds(10)));
		TIMEIT(sleep_for(10));
	}
}



#include <catch2/catch_test_macros.hpp>
#include <scoped_timer.h>

#include <thread>

TEST_CASE("scoped timer", "[enum][hide]")
{
	{
		ScopedTimer sc;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}



#include "stdafx.h"
#include <scoped_timer.h>

#include <thread>

int sleep_for(int ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
	return ms;
}

TEST(cpp_rutils,scoped_timer)
{
	{
		ScopedTimer sc("test0");
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		voidTIMEIT("test1",  std::this_thread::sleep_for(std::chrono::milliseconds(10)))
		TIMEIT("test2",sleep_for(10));
	}
}



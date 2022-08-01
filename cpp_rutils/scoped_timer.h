#pragma once

#include <chrono>
#include <iostream>

class ScopedTimer
{
public:
	ScopedTimer() : _start_time(std::chrono::steady_clock::now())
	{
	}

	~ScopedTimer()
	{
		auto elapsed_time = std::chrono::steady_clock::now() - _start_time;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time).count();
		std::cout << "The elapsed time was " << ms << " ms.\n";
	}

private:
	std::chrono::time_point<std::chrono::steady_clock> _start_time;

};

struct TimeIt
{
	TimeIt() : _sc() {}
	auto        fun(auto&& t) { return std::forward<decltype(t)>(t); }
	ScopedTimer _sc;
};

// macro to time a block of code
// when using with template, encapsulate in double parentheseses
// e.g. TIMEIT(( std::vector<int>(100) )) ;
#define TIMEIT(a) TimeIt().fun(a)


#define voidTIMEIT(a) \
  {                   \
    ScopedTimer _sc;  \
    a;                \
  }


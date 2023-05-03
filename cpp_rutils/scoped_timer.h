#pragma once

#include <chrono>
#include <iostream>

class ScopedTimer
{
public:
	ScopedTimer() = delete;
	explicit ScopedTimer(std::string what) { start(std::move(what)); }
	~ScopedTimer() { end(); }

	void restart(std::string what)
	{
		end();
		start(std::move(what));
	}

private:
	std::string                                        _what;
	std::chrono::time_point<std::chrono::steady_clock> _start_time;

	void start(std::string&& what)
	{
		_what = std::move(what);
		_start_time = std::chrono::steady_clock::now();
		std::cout << "[ " << _what << std::flush;
	}
	void end()
	{
		auto elapsed_time = std::chrono::steady_clock::now() - _start_time;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time).count();
		std::cout << " took " << ms << " ms ]\n ";
	}
};

struct TimeIt
{
	TimeIt(const std::string& what) : _sc(what) {}
	auto        fun(auto&& t) { return std::forward<decltype(t)>(t); }
	ScopedTimer _sc;
};

// macro to time a block of code
// when using with template, encapsulate in double parentheseses
// e.g. TIMEIT(( std::vector<int>(100) )) ;
//#define TIMEIT(what, a) TimeIt(what).fun(a)

#define TIMEIT(what, a) \
  [&]()                 \
  {                     \
    ScopedTimer _st(what);  \
    return a;           \
  }()

// macro for non-returning code
#define voidTIMEIT(what, a) \
  {                         \
    ScopedTimer _st{what};  \
    a;                      \
  }

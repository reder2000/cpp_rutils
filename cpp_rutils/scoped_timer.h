#pragma once

#include <chrono>
#include <iostream>

class ScopedTimer
{
public:
    ScopedTimer() : _start_time ( std::chrono::steady_clock::now())
    {
    }

    ~ScopedTimer()
    {
        auto elapsed_time = std::chrono::steady_clock::now() - _start_time;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed_time).count();
        std::cout << "The elapsed time was " << ms << " ms.\n";
    }


private:
    std::chrono::time_point<std::chrono::steady_clock> _start_time ;

};


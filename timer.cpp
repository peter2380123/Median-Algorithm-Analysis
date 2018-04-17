extern "C"
{
#include "timer.h"
}
#include <chrono>

long long get_monotime()
{
    auto now_ns = std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now());
    return std::chrono::duration_cast<std::chrono::nanoseconds>(now_ns.time_since_epoch()).count();
}

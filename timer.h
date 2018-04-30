#pragma once
// Get the the internal mono time in milliseconds. Mono time is not necessarily
// the clock time, but it is guaranteed that while your computer is on, you can
// use the difference between two readings of the monotime to get the amount of
// time between two events.
long long get_monotime();

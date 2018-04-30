#pragma once
// Uniformly generates a pseudorandom number using the Merseinne Twister
// algorithm from the C++ standard library. Unlike rand(), the standard
// guarantees that the distribution is uniform.
//
// Inputs
// ------
// inclusiveMin:
//  The lower bound, inclusive.
//
// inclusiveMax:
//  The upper bound, inclusive.
//
int mt_random(int inclusiveMin, int inclusiveMax);


// Provide bindings for C files.
extern "C" int mt_random(int inclusiveMin, int inclusiveMax);

// C++
#include <random>

int mt_random(int inclusiveMin, int inclusiveMax)
{
    static std::random_device rd;
    static std::mt19937 gen(rd()); // Seed.
    static std::uniform_int_distribution<> dis(inclusiveMin, inclusiveMax);
    
    return dis(gen);
}

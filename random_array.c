#include <stdlib.h>
#include <limits.h>

#include "random_array.h"
#include "mt_random.h"

void populate_random(int *mem, const size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        mem[i] = mt_random(INT_MIN, INT_MAX);
    }
}

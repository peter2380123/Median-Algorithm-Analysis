#include <stdlib.h>
#include <limits.h>

#include "random_array.h"
#include "mt_random.h"

int *create_random(const size_t size)
{
    int *result = malloc(size * sizeof(int));

    for (size_t i = 0; i < size; ++i)
    {
        result[i] = mt_random(INT_MIN, INT_MAX);
    }

    return result;
}

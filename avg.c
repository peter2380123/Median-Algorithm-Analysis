#include "avg.h"
#include "stddef.h"

double average_values(long long *arr, size_t N)
{
    double multi = 1.0 / N;
    double result = 0;

    for (size_t i = 0; i < N; ++i)
    {
        result += arr[i] * multi;
    }

    return result;
}

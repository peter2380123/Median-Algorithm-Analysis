#include "qmedian.h"

#define SWAP(x, y) \
do                 \
{                  \
    int tmp = x;   \
    x = y;         \
    y = tmp;       \
} while (0);


#ifdef COUNT_OPS
static size_t _quickBasicOps = 0;

size_t qm_getBasicOps()
{
    return _quickBasicOps;
}
#endif

size_t qm_median(int *arr, size_t size)
{
    if (size == 1)
    {
        return arr[0];
    }
    else
    {
       return _qm_select(arr, 0, size/2, size-1);
    }
}

size_t _qm_select(int *arr, size_t low, size_t middle, size_t high)
{
    size_t pos = _qm_partition(arr, low, high);
    if (pos == middle)
    {
        return arr[pos];
    }
    else if (pos > middle)
    {
        return _qm_select(arr, low, middle, pos - 1);
    }
    else /* if (pos < middle) */
    {
        return _qm_select(arr, pos+1, middle, high);
    }
}

size_t _qm_partition(int *arr, size_t low, size_t high)
{
    int    pivot_value       = arr[low];
    size_t pivot_location    = low;

    for (size_t j = low+1; j <= high; ++j)
    {
        if (arr[j] < pivot_value)
        {
            ++pivot_location;
            SWAP(arr[pivot_location], arr[j]);
        }
#ifdef COUNT_OPS
        ++_quickBasicOps;
#endif
    }
    SWAP(arr[low], arr[pivot_location]);
    
    return pivot_location;
}

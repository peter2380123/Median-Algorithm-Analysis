#include "bfmedian.h"
#include "stdio.h"
#include "math.h"

#ifdef COUNT_OPS
static size_t _bfmBasicOps = 0;

size_t bfm_getBasicOps()
{
    return _bfmBasicOps;
}
#endif

size_t bfm(int *arr, size_t size)
{
	int k = ceil(size / 2.0);

	for (int i = 0; i < size; i++)
	{
		int numsmaller = 0;
		int numequal = 0;

		for (int j = 0; j < size; j++)
		{
			if (arr[j] < arr[i])
			{
				numsmaller++;
			}
			else
			{
				if (arr[j] == arr[i])
				{
					numequal++;
				}
			}
#ifdef COUNT_OPS
			_bfmBasicOps++;
#endif
		}

		if (numsmaller < k && k <= (numsmaller + numequal))
		{
			return arr[i];
		}
	}

}

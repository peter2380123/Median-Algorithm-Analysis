# include "bfmedian.h"
# include "stdio.h"
# include "math.h"

size_t bfm(int *arr, size_t size)
{
	int k = round(size / 2);

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
		}

		if (numsmaller < k && k <= (numsmaller + numequal))
		{
			return arr[i];
		}
	}

}
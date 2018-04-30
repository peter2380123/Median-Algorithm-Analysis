#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// C++ bindings
#include "mt_random.h" // Merseinne Twister
#include "timer.h"     // chrono
#include "avg.h"

// Our median implementations.
#include "qmedian.h"  // Quick median.
#include "bfmedian.h" // Brute-force median.

#define MAX(x, y) (((x) >= (y)) ? (x) : (y))

int main(int argc, char *argv[])
{
    size_t start, stop, numIncrements, numTrials;

#ifdef __GNUC__
    if (argc < 4 || argc > 5)
    {
        printf("./median start stop numberOfIncrements numberOfTrials\n");
        return -1;
    }
    start = atoi(argv[1]);
    stop = atoi(argv[2]); 
    numIncrements = atoi(argv[3]); 
    numTrials = 1;
    if (argc == 5)
    {
        numTrials = atoi(argv[4]);
    }
#elif _MSC_VER_

#endif

    double increment = MAX(1, (stop - (double)start) / MAX(1, numIncrements-1));

    int *data = malloc(stop * sizeof(int));
    if (data == NULL)
    {
        printf("Could not allocate memory. Try a smaller end size.\n");
        return -1;
    }

    // Placeholder stuff.
    printf("start: %zu\tstop: %zu\tnumIncrements: %zu\tnumTrials: %zu\n", start, stop, numIncrements, numTrials);

    for (double i_ = start; i_ <= stop; i_ += increment)
    {
        const size_t i = round(i_); // Do not change.
        printf("i = %zu\n", i);
    }

    // Our output file.
    FILE *f = fopen("results.csv", "w");
    fprintf(f, "INPUT_SIZE, BRUTE_NUM_OPERATIONS, BRUTE_NANOSECONDS, QUICK_NUM_OPERATIONS, QUICK_NANOSECONDS\n");

    free(data);

    return 0;
}

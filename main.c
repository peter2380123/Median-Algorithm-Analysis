#include <stdio.h>
#include <stdlib.h>

// C++ bindings
#include "mt_random.h" // Merseinne Twister
#include "timer.h"     // chrono
#include "avg.h"

// Our median implementations.
#include "qmedian.h"  // Quick median.
#include "bfmedian.h" // Brute-force median.

// Testing testing 123 from Visual Studio.

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


    int *data = malloc(stop * sizeof(int));
    if (data == NULL)
    {
        printf("Could not allocate memory. Try a smaller end size.\n");
        return -1;
    }

    // Placeholder stuff.
    printf("start: %zu\tstop: %zu\tnumIncrements: %zu\tnumTrials: %zu\n", start, stop, numIncrements, numTrials);

    // Our output file.
    FILE *f = fopen("results.csv", "w");
    fprintf(f, "INPUT_SIZE, BRUTE_NUM_OPERATIONS, BRUTE_NANOSECONDS, QUICK_NUM_OPERATIONS, QUICK_NANOSECONDS\n");

    return 0;
}

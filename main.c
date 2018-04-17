#include <stdio.h>
#include <stdlib.h>

// C++ bindings
#include "mt_random.h" // Merseinne Twister
#include "timer.h"     // chrono

// Our median implementations.
#include "qmedian.h"
#include "bfmedian.h"

int main(int argc, char *argv[])
{
    long t0 = get_monotime();

    if (argc < 4 || argc > 5)
    {
        printf("./median start stop numberOfIncrements numberOfTrials\n");
        return -1;
    }

    size_t start = atoi(argv[1]), stop = atoi(argv[2]), numIncrements = atoi(argv[3]), numTrials = 1;

    if (argc == 5)
    {
        numTrials = atoi(argv[4]);
    }

    printf("start: %zu\tstop: %zu\tnumIncrements: %zu\tnumTrials: %zu\n", start, stop, numIncrements, numTrials);
    long tf = get_monotime();

    printf("Nanoseconds: %ld\n", tf - t0);

    return 0;
}

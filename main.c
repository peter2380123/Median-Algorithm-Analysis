#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// C++ bindings
#include "mt_random.h" // Merseinne Twister
#include "timer.h"     // chrono
#include "avg.h"

// Our median implementations.
#include "qmedian.h"  // Quick median.
#include "bfmedian.h" // Brute-force median.

#define MAX(x, y) (((x) >= (y)) ? (x) : (y))

#ifdef COUNT_OPS
const char *brute_result = "BRUTE_OPERATIONS";
const char *quick_result = "QUICK_OPERATIONS";
#else
const char *brute_result = "BRUTE_TIME";
const char *quick_result = "QUICK_TIME";
#endif

// A helper function to fill an existing array with random values.
static void populate_random(int *mem, const size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        mem[i] = mt_random(INT_MIN, INT_MAX);
		//mem[i] = i + 1; // for values 1 to n, ascending (sorted). 
		//mem[i] = size - i; // for values n to 1, descending (unsorted).
    }
}

// Program entry point.
int main(int argc, char *argv[])
{
    size_t start, stop = 100, numIncrements = 1, numTrials = 1;

#if _MSC_VER
    /*unsigned int start_value;
      unsigned int stop_value;
      int numIncrements;
      int numTrial;*/
    printf("Declare inclusive start size of the random array: ");
    scanf("%zu", &start);
    printf("Declare inclusive stop size of the random array: ");
    scanf("%zu", &stop);
    printf("Number of increments: ");
    scanf("%zu", &numIncrements);
    printf("Number of trials to run: ");
    scanf("%zu", &numTrials);

	printf("\n");
#else
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
#endif

    double increment = MAX(1, (stop - (double)start) / MAX(1.0, ((double)numIncrements-1.0)));

    // Allocate a contiguous block of memory the size of our largest N size.
    // This way, we avoid continuously allocating and freeing memory of various
    // sizes, which can inconsistently affect the performance due to caching.
    // We don't initialise to 0 because we are going to overwrite the values
    // anyway.
    int *data = malloc(MAX(start, stop) * sizeof(int));

    // As a side-effect, we can now also stop the program from running if the
    // largest N size is too big for the computer's memory.
    if (data == NULL)
    {
        printf("Could not allocate memory. Try a smaller N. (You entered %zd)\n", MAX(start, stop));
        return -1;
    }

    // Our output file.
    FILE *f = fopen("results.csv", "w");
    fprintf(f, "INPUT_SIZE, %s, %s\n", brute_result, quick_result);

    // For every N...
    for (double i = start; round(i) <= stop; i += increment)
    {
        const size_t N = round(i);

        // These variables will hold the total measurement.
        double bfTotal = 0, quickTotal = 0;

        // Trial it numTrials times.
        for (size_t trial = 1; trial <= numTrials; ++trial)
        {

            // Give user some feedback to what is happening.
            printf("Trial %zu of %zu, n = %zu", trial, numTrials, N);
			if (N % 2 == 0) {
				printf(" (even number, expect different Median result)\n");
			}
			else
				printf(" (odd number, should have the same Median)\n");

            // Populate data with random values, using the standardised
            // Merseinne Twister implementation from C++. We use this instead of
            // rand() because the quality of rand() is implementation-defined,
            // while the quality of C++'s Merseinne Twister is guaranteed. The
            // trade-off for this is that this program must be compiled on a
            // machine with both a C and C++ compiler -- which is guaranteed in
            // this subject as both languages are accepted.
            populate_random(data, N);

			/*
			printf("Generated values: ");
			for (size_t i = 0; i < N; i++) {
				if (i == 0) 
				{
				}
				else
				{
					printf(", ");
				}
				printf("%d",data[i]);
			}
			printf("\n");
			*/


			

            long long t0, tf;
			int result;
            // We're doing a comparison, and therefore should have the functions
            // both find the median from the same sequence of numbers. Note that
            // brute force median causes no side-effects, but quick median does.
            // Therefore, we run brute force median first.
#ifndef COUNT_OPS // TODO: Switch around when both implemented.
            t0 = get_monotime();
            result = bfm(data, N);
            tf = get_monotime();
			printf("The brute-force median selected was: %d", result);
			printf(", and time measured was: %lld nanoseconds\n", tf - t0);

            bfTotal += tf - t0;

            // Now our quick median.
            t0 = get_monotime();
			result = qm_median(data, N);
            tf = get_monotime();
			printf("The quick median selected was: %d", result);
			printf(", and time measured was: %lld nanoseconds\n", tf - t0);

			printf("\n");
            quickTotal += tf - t0;
#else
            // Code to count basic operations goes here.
#endif
        } // end trials for.

        // At this point, we need to take the average to make any sense of our
        // result. Awkward cast to make sure this is not an integer division.
        double bfAverage = bfTotal / (double)numTrials;
        double quickAverage = quickTotal / (double)numTrials;

        // Now we an write this result into the file, appending it to whatever
        // was there last.
        fprintf(f, "%zd, %f, %f\n", N, bfAverage, quickAverage);

    } // end N for.

    free(data);
    fclose(f);

    return 0;


}

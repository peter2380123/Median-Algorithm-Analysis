#include <stdio.h>

// C++ bindings for the Merseinne Twister.
#include "mt_random.h"

#include "timer.h"

// Our median implementations.
#include "qmedian.h"
#include "bfmedian.h"

int main(int argc, char *argv[])
{
    if (argc == 5) // User has explicitly asked for number of trials.
    {
    }
    if (argc <= 4)
    {
    }
    else
    {
        printf("./median start stop numberOfIncrements numberOfTrials\n");
        return -1;
    }
    return 0;
}

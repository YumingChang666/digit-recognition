//
// Created by 23503 on 2022/11/21.
//

/*===============================================================*/
/*                                                               */
/*                    digit_recognition.cpp                      */
/*                                                               */
/*   Main host function for the Digit Recognition application.   */
/*                                                               */
/*===============================================================*/

// standard C/C++ headers
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
//#include <string>
#include <time.h>
#include <sys/time.h>

#ifdef SW
# include "../sw/digitrec_sw.h"
#endif

// other headers
#include "utils.h"
#include "typedefs.h"
#include "check_result.h"

// data
#include "training_data.h"
#include "testing_data.h"

int main(int argc, char ** argv)
{
    printf("Digit Recognition Application\n");

    // for this benchmark, data is already included in arrays:
    //   training_data: contains 18000 training samples, with 1800 samples for each digit class
    //   testing_data:  contains 2000 test samples
    //   expected:      contains labels for the test samples

    // timers
    struct timeval start, end;

    // sw version host code
#ifdef SW
    // create space for the result
    LabelType* result = new LabelType[NUM_TEST];

    // software version
    gettimeofday(&start, NULL);
    DigitRec_sw(training_data, testing_data, result);
    gettimeofday(&end, NULL);
#endif

    // check results
    printf("Checking results:\n");
    check_results( result, expected, NUM_TEST );

    // print time
    long long elapsed = (end.tv_sec - start.tv_sec) * 1000000LL + end.tv_usec - start.tv_usec;
    printf("elapsed time: %lld us\n", elapsed);

    // cleanup
#ifdef SW
    delete []result;
#endif

    return EXIT_SUCCESS;

}
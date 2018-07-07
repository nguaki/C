#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include <dbg.h>
#include <stdlib.h>

#define mu_suite_start() char *message = NULL

/////////
//#e.g. mu_assert( file != NULL, "File not found");
//       Checks boolean expression: file != NULL.
//    If boolean expression is true, !true is false. Do nothing.
//    If boolena expression is false, !false is true. DO something.
//
//    In short, do something if boolean expresssion is false.
/////////
#define mu_assert(test, message) if (!(test)) {\
    log_err(message); return message; }
    
/////////
//test is actually a name of a function.
//test() does the actual function call.
//
//test() returns either NULL or a message indicating
//   specific error message.
//
//If message is not NULL (meaning there was an error),
//  the function which contains this statement will
//  not continue.
//
// e.g.  mu_run_test(test_dl_open);
//       This statement will provoke test_dl_open() function.
//
///////////////////////////
#define mu_run_test(test) debug("\n-----%s", " " #test); \
    message = test(); tests_run++; if (message) return message;

///////////////////////////
// name is a name of the function.  (e.g. all_tests)
// name() cauese actual function call.
// If any of the statements in the function returns with NON NULL,
// result will be not zero. This means the test has failed.
//
// e.g. RUN_TESTS(all_tests);
//      This will provoke all_tests(); function call.
//
///////////////////////////
#define RUN_TESTS(name) int main(int argc, char *argv[]) {\
    argc = 1; \
    debug("----- RUNNING: %s", argv[0]);\
    printf("----\nRUNNING: %s\n", argv[0]);\
    char *result = name();\
    if (result != 0) {\
        printf("FAILED: %s\n", result);\
    }\
    else {\
        printf("ALL TESTS PASSED\n");\
    }\
    printf("Tests run: %d\n", tests_run);\
    exit(result != 0);\
}

///////////////////////////////////////////////////////////
//#This variable keeps track of number of  tests.
///////////////////////////////////////////////////////////
int tests_run;

#endif
#include "minunit.h"
#include <dlfcn.h>

typedef int (*lib_function) (const char *data);
char *lib_file = "build/libYOUR_LIBRARY.so";
void *lib = NULL;

////////////////////////////////////////////////////////////
//
// Calls actual function from the shared lib.
// Checks if it meets the expected value.
//
////////////////////////////////////////////////////////////
int check_function(const char *func_to_run, const char *data,
        int expected)
{
    //From shared library, get a handle on a function.
    lib_function func = dlsym(lib, func_to_run);
    
    //Check if function pointer is not NULL.
    check(func != NULL,
            "Did not find %s function in the library %s: %s", func_to_run,
            lib_file, dlerror());

    //Call the function and retrieve returned value.
    int rc = func(data);
    
    //Check if returned value meets expected value.
    check(rc == expected, "Function %s return %d for data: %s",
            func_to_run, rc, data);

    return 1;
    
    //If there is an error, it will jump to 'error' label.

error:
    return 0;

}

/////////////////////////////////////////////////////////
//Tests if dynamic library can be interfaced.
/////////////////////////////////////////////////////////
char *test_dlopen()
{
    lib = dlopen(lib_file, RTLD_NOW);
    
    //////////////////////////////////////////////
    //Check if lib is not a NULL.
    //If it is a NULL, need to say so.
    //Note that lib is NULL, mu_assert() will return
    //and it will not execute "return N.ULL" statement
    //////////////////////////////////////////////
    mu_assert(lib != NULL, "Failed to open the library to test.");

    return NULL;
}

///////////////////////////////////////////////////////
// Checks each function.
///////////////////////////////////////////////////////
char *test_functions()
{
    mu_assert(check_function("print_a_message", "Hello", 0),
            "print_a_message failed.");
    mu_assert(check_function("uppercase", "Hello", 0),
            "uppercase failed.");
    mu_assert(check_function("lowercase", "Hello", 0),
            "lowercase failed.");
    mu_assert(check_function("alternate", "WarriorsLakers", 0),
            "alternate failed.");

    return NULL;
}

char *test_failures()
{
    mu_assert(check_function("fail_on_purpose", "Hello", 1),
            "fail_on_purpose should fail.");

    return NULL;
}

////////////////////////////////////////////////////////
//Checks if shared library closed properly.
////////////////////////////////////////////////////////
char *test_dlclose()
{
    int rc = dlclose(lib);
    mu_assert(rc == 0, "Failed to close lib.");

    return NULL;
}

/////////////////////////////////////////////////////////
//
// Each mu_run_test() will invoke a test function.
// If any function fails, it will return immediately.
// Although, there is no return statement apparent,
// mu_run_test() is a macro which returns upon failure.
//
// Each test function has mu_assert() statement.
// If mu_assert() fails, it returns an error message.
//
// mu_run_test() checks if returned message is 0.
// If it is not 0, it means it returns error message.
// If it returns error message, this function will return
// immediately.
//
// Each mu_run_test() will increment test count.
//
//////////////////////////////////////////////////////////
char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_dlopen);
    mu_run_test(test_functions);
    mu_run_test(test_failures);
    mu_run_test(test_dlclose);

    return NULL;
}

//This is actually the main.
RUN_TESTS(all_tests);
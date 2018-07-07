// March 7, 2017
//
// This works in conjuction with libex29.so(shard library) which is created using
// libex29.c
//
// cc -Wall -g -DNDEBUG ex29.c -ldl -o ex29
//             -ldl is needed for dlfcn.h functions.
//
// ./ex29 ./libex29.so print_a_message "hello there"
//  A message: hello there
//
//./ex29 ./libex29.so uppercase "hello there"
// HELLO THERE
//
//./ex29 ./libex29.so lowercase "HELLO there"
// hello there
//
//./ex29 ./libex29.so xyz "HELLO there"
// [ERROR](ex29.c22: error no:None)Did not find xyz function in the library 
// ./libex29.so:./libex29.so: undefined symbol: xyz


#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>

typedef int (*lib_function)(const char *data);

int main( int argc, char *argv[] )
{
    int rc = 0;
    
    
    check( argc == 4, "USAGE: ex29 libex29.so function data");
    
    char *lib_file = argv[1];
    char *func_to_run = argv[2];
    char *data = argv[3];
    
    void *lib = dlopen(lib_file, RTLD_NOW);
    check(lib != NULL, "Failed to open the library %s %s", lib_file, dlerror());
    
    lib_function func = dlsym(lib, func_to_run);
    check(func != NULL, "Did not find %s function in the library %s:%s", func_to_run, lib_file, dlerror() );
    
    rc = func(data);
    check( rc == 0, "function %s return %d for data: %s", func_to_run, rc, data);
    rc = dlclose(lib);
    check( rc==0, "Failed to close %s", lib_file);
    
    return 0;

error:
    return -1;
}
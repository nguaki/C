///////////////////////////////////////////////////////////////////////
//
//  This file is used for error checking, logging and debugging.
//
///////////////////////////////////////////////////////////////////////
#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifdef NDEBUG
////////////////////////////////////////////////////////////////////////
//if NDEBUG is specified when compiling. e.g. cc -DNDEBUG
//Nothing is defined. So nothing happens.
////////////////////////////////////////////////////////////////////////
#define debug(M, ...)
#else
////////////////////////////////////////////////////////////////////////
// e.g. debug( "fopen failed for %s", fileName );
// The above statement will create following line:
//         DEBUG libex29.c:55 fopen failed for xyz.
//           where M            = "fopen failed for %s"
//                 ##_VA_ARGS__ = "xyz"
////////////////////////////////////////////////////////////////////////
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n",\
                              __FILE__, __LINE__, ##__VA_ARGS__)
#endif

////////////////////////////////////////////////////////////////////////
//The returning value is either "None" or system error message.
////////////////////////////////////////////////////////////////////////
#define clean_errno() (errno == 0 ? "None" : strerror(errno))

////////////////////////////////////////////////////////////////////////
//e.g.
// log_error("%s file does not exists.", fileName );
// [ERROR] (libex29.c:45: errno: File Not found) libex29.c file does not exists. 
////////////////////////////////////////////////////////////////////////
#define log_err(M, ...) fprintf(stderr,\
        "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__,\
        clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr,\
        "[WARN] (%s:%d: errno: %s) " M "\n",\
        __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n",\
        __FILE__, __LINE__, ##__VA_ARGS__)
        
////////////////////////////////////////////////////////////////////////
//e.g.   check( file != NULL, "File %s Not found.", fileName);
//
// Checks boolean value of  Bool = (file!=NULL).
//        If Bool == true => !Bool = false. Nothing happens
//        If Bool == false => !Bool = true. logs an error.
//
// Shortly, it checks if expression 'A' is false.
// If it is false, 
//      (1)it will log a message.
//      (2)set errno to 0
//      (3)jump to error label.
////////////////////////////////////////////////////////////////////////
#define check(A, M, ...) if(!(A)) {\
    log_err(M, ##__VA_ARGS__); errno=0;  goto error; }
///////////////////////////////////////////////////////////////////////
//Same as log_err() except there is no condition.
///////////////////////////////////////////////////////////////////////
#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__);\
    errno=0; goto error; }
//////////////////////////////////////////////////////////////////////
//This macro is used for checking memory.
//////////////////////////////////////////////////////////////////////
#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__);\
    errno=0; goto error; }

#endif
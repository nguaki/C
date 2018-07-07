#ifndef __dbg__
#define __dbg__

#include <stdio.h>
#include <string.h>
#include <errno.h>


#ifdef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprintf(stderr, "%s:%d:" M "\n", \
                        __FILE__, __LINE__, ##__VA_ARGS__ )
#endif

#define clean_errno() (errno == 0 ? "None" :strerror(errno))

#define log_err(M, ...) fprintf(stderr,\
                    "[ERROR](%s%d: error no:%s)" M "\n", __FILE__, __LINE__,\
                    clean_errno(), ##__VA_ARGS__)
                        
#define check(A, M, ...) if(!(A)){ \
    log_err(M, ##__VA_ARGS__); errno = 0; goto error; }

#define sentinel(M, ... ) {log_err(M, ##__VA_ARGS__);\
    errno = 0; goto error;}
    
#define check_mem(A) check((A), "Out of memory.")

#endif
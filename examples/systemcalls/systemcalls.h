 #ifndef sysCalls_H
 #define sysCalls_H
#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>  
#include <ctype.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <fcntl.h>
 #include <sys/stat.h>

bool do_system(const char *command);

bool do_exec(int count, ...);

bool do_exec_redirect(const char *outputfile, int count, ...);
#endif
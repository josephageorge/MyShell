#include <stdio.h>
#include <errno.h>

#define PERROR() perror("ERROR")
#define OUT_OF_MEMORY() perror("FATAL ERROR");\
                        exit(137);

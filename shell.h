#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

/* Shell Initialization */
int main(int ac, char **av, char **env);

#endif /* SHELL_h */

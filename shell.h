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

/* Run Shell */
int main(int ac, char **av, char **env);
void prompt(void);
void handle_signal(int num);
void _EOF(char *buffer);
void shell_exit(char **command);

void print_env(char **env);
int own_cmd_handler(char **parsed);
int execute(char **args);



/* helper_string */
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *s);

#endif /* SHELL_H */

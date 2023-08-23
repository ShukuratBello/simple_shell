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
int main(int ac, char **av, char **envp[]);
void prompt(void);
int launch(char **args);
void print_env(void);
int own_cmd_handler(char **parsed);
int execute(char **args);
void handle_signal(int num);
char *read_line(void);
char **split_line(char *line);

/* helper_string */
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *s);

/* helper function for efficient free */
void free_buffers(char **buf);

/* about builtin */
struct builtin
{
	char *env;
	char *exit;
} builtin;

/* about info */
struct info
{
	int final_exit;
	int ln_count;
} info;

/* about flags */
struct flags
{
	bool interactive;
} flags;

#endif /* SHELL_H */

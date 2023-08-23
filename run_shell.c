#include "shell.h"
/**
 * own_cmd_handler - handles cmd
 * @parsed: parser
 * Return: 0
 */

int own_cmd_handler(char **parsed)
{
	int NoOfOwnCmds = 2, i, switchOwnArg = 0;
	char *ListOfOwnCmds[NoOfOwnCmds];

	ListOfOwnCmds[0] = "exit";
	ListOfOwnCmds[1] = "env";

	for (i = 0; i < NoOfOwnCmds; i++)
	{
		if (_strcmp(parsed[0], ListOfOwnCmds[i]) == 0)
		{
			switchOwnArg = i + 1;
			break;
		}
	}

	switch (switchOwnArg)
	{
		case 1:
			exit(0);
		case 2:
			print_env();
			return (1);
		default:
			break;
	}

	return (0);
}

/**
 * execute - execute the args
 * @args: list of args
 * Return: 1 on success
 */
int execute(char **args)
{
	if (own_cmd_handler(args))
	{
		return (0);
	}
	else if (**args == '/')
	{
		return (launch(args));
	}
	return (0);
}

/**
 * print_env - A function that prints all enviromental variables.
 * @env: The pointer to enviromental variables.
 * Return: Nothing.
 */
void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

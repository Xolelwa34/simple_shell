#include "shell.h"

/**
 * assist_env - presents the information on shell by the ready- built command 'env'
 */
void assist_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * assist_setenv - Presents the information on shell by the ready- built command 'setenv'
 */
void assist_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * assist_unsetenv - Presents the information on shell by the ready- built command
 * 'unsetenv'
 */
void help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * present_assis - Functions that presents assistance for the builtin commands
 * @cmd: parses command
 * @st: Status of the  last command executed
 * Return: Always 0
 */
int present_assist(char **cmd, __attribute__((unused))int st)
{
	if (!cmd[1])
		assist_all();
	else if (_strcmp(cmd[1], "alias") == 0)
		assist_alias();
	else if (_strcmp(cmd[1], "cd") == 0)
		assist_cd();
	else if (_strcmp(cmd[1], "exit") == 0)
		assist_exit();
	else if (_strcmp(cmd[1], "env") == 0)
		assist_env();
	else if (_strcmp(cmd[1], "setenv") == 0)
		assist_setenv();
	else if (_strcmp(cmd[1], "unsetenv") == 0)
		assist_unsetenv();
	else if (_strcmp(cmd[1], "assist") == 0)
		assist_inuse();
	return (0);
}


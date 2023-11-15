#include "shell.h"

/**
 * find_builtin - function that exemine commands
 * @cmd: command to be checked
 * Return: 0 Succes, -1 on error
 */
int find_builtin(char **cmd)
{
	builtin simple[] = {
		{"cd", NULL},
		{"assist", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int a = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((simple + a)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		a++;
	}
	return (-1);
}

/**
 * handle_builtin - function that handles the builin commands
 * @cmd: parsed command strings
 * @st: execution status
 * Return: Always 0 succes, -1 on error
 */
int handle_builtin(char **cmd, int st)
{
	builtin built_in[] = {
		{"cd", change_directory},
		{"env", display_env},
		{"assist",present_assist},
		{"echo", echo_bulp},
		{"history", his_display},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_in + a)->command)
	{
		if (_strcmp(cmd[0], (built_in + a)->command) == 0)
		{
			return ((built_in + a)->function(cmd, st));
		}
		a++;
	}
	return (-1);
}

/**
 * exit_bulp -function that exit tatuses for built-in commands
 * @cmd: parsed command strings
 * @input: Input for user to be freed
 * @argv: Arguments
 * @c: shell count exec
 * @fir: Exit status
 */
void exit_bulp(char **cmd, char *input, char **argv, int c, int first)
{
	int first, a = 0;

	if (cmd[1] == NULL)
	{
		list(input);
		list(cmd);
		exit(first);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][a++]) != 0)
		{
			_prerror(argv, q, cmd);
			list(input);
			list(cmd);
			exit(2);
		}
		else
		{
			sta = _atoi(cmd[1]);
			if (sta == 2)
			{
				_prerror(argv, q, cmd);
				list(input);
				list(cmd);
				exit(sta);
			}
			list(input);
			list(cmd);
			exit(sta);

		}
	}
}


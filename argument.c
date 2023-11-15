#include "shell.h"
#include <stdio.h>

/**
 * view_file - Views the commands from argument file
 * @file: commands file
 * @argv: Arguments
 * Return 0 Success
 */
void view_file(char *file, char **argv)
{
	FILE *fn;
	char *line = NULL;
	size_t length = 0;
	int value = 0;

	fn = fopen(file, "r");
	if (fn == NULL)
	{
		error_file(argv, value);
		exit(127);
	}
	while ((getline(&line, &length, fn)) != -1)
	{
		value++;
		ask_file(line, value, fn, argv);
	}
	if (line)
		list(line);
	fclose(fn);
	exit(0);
}

/**
 * ask_file - Parse commands and handle their execution
 * @line: file line
 * @count: error
 * @fp: f descriptor
 * @argv: arguments command line
 */
void ask_file(char *line, int value, FILE *fn, char **argv)
{
	char **cmd;
	int stat = 0;

	cmd = path_cmd(line);
	if (_strncmp(cmd[0], "exit", 4) == 0)
		exit_bulp_the_file(cmd, line, fn);
	else if (check_builtin(cmd) == 0)
	{
		flag = handle_builtin(cmd, flag);
		list(cmd);
	}
	else
	{
		flag = check_cmd(cmd, line, value, argv);
		list(cmd);
	}
}

/**
 * exit_bulp_for_file - Function that exits the handler
 *line - file line
 * @cmd: command passer
 * @fd: f descriptor
 */
void exit_bulp_for_file(char **cmd, char *line, FILE *fn)
{
	int status;
	int a = 0;

	if (cmd[a] == NULL)
	{
		list(line);
		list(cmd);
		fclose(fn);
		exit(errno);
	}
	while (cmd[1][a])
	{
		if (_isalpha(cmd[1][a++]) < 0)
			perror("Illicit number");
	}
	status = _atoi(cmd[1]);
	list(line);
	list(cmd);
	fclose(fn);
	exit(status);
}


#include "shell.h"

/**
 * path_cmd -  Searches path for executeble commands
 * @cmd: Input parse
 * Return: 0 on success,-1 on error
 */
int path_cmd(char **cmd)
{
	char *path, *number, *cmd_path;
	struct status buf;

	path = _getenv("PATH");
	number = _strtok(path, ":");
	while (number != NULL)
	{
		cmd_path = own(*cmd, number);
		if (status(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			list(cmd_path);
			list(path);
			return (0);
		}
		list(cmd_path);
		number = _strtok(NULL, ":");
	}
	list(path);
	list(number);
	return (1);
}

/**
 * make - making command
 * @token: exec command
 * @value: dir that contains commands
 * Return: 0 Success
 */
char *make(char *token, char *number)
{
	char *cmd;
	size_t length;

	length = _strlen(numbetr) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * length);
	if (cmd == NULL)
	{
	list(cmd);
		return (NULL);
	}

	memset(cmd, 0, length);

	cmd = _strcat(cmd, number);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}

/**
 * _find-env - environment variables
 * @n: env variable names
 * Return: 0 Success
 */
char *_find-env(char *name)
{
	size_t got_length, number_length;
	char *number;
	int a, r, d;

	name_length = _strlen(name);
	for (a = 0 ; environ[a]; a++)
	{
		if (_strncmp(name, environ[a], got_length) == 0)
		{
			number_length = _strlen(environ[i]) - got_length;
			number = malloc(sizeof(char) * number_length);
			if (!number)
			{
				list(number);
				perror("unable to alloc");
				return (NULL);
			}

			r = 0;
			for (d = got_length + 1; environ[a][d]; d++, r++)
			{
				number[r] = environ[a][d];
			}
			number[r] = '\0';

			return (number);
		}
	}
	return (NULL);
}


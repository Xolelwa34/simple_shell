#include "shell.h"

/**
 * cd - Changes the directory
 * @cmd: parses the command
 * @st: status of the command executed
 * Return: 0 on success,1 on error
 */
int cd(char **cmd, __attribute__((unused))int st)
{
	int number = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		number = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
	{
		number = chdir(getenv("OLDPWD"));
	}
	else
		number = chdir(cmd[1]);

	if (number == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (number != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * get_env - presents the variable environment
 * @cmd: parses the command
 * @st: status of the command executed
 * Return: Always 0
 */
int get_env(__attribute__((unused)) char **cmd, __attribute__((unused)) int st)
{
	size_t a;
	int flag;

	for (a = 0; envi[a] != NULL; a++)
	{
		flag = _strlen(envi[a]);
		list(1, envi[a], flag);
		list(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/**
 * echo_bulp - function that execute echo
 * @st: status of the command executed
 * @cmd: parses the command
 * Return: Always 0 success
 */
int echo_bulp(char **cmd, int st)
{
	char *process;
	unsigned int pid = getppid();

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_sum(st);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_sum(pid);
		PRINT("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		process = _getenv("PATH");
		PRINT(process);
		PRINT("\n");
		write(process);
	}
	else
		return (print_echo(cmd));

	return (1);
}

/**
 * his_display - function that presents the history of user input on simple_shell
 * @c: parses the command
 * @st: status of the command executed
 * Return: 0 success or -1 on error
 */
int his_display(__attribute__((unused))char **c, __attribute__((unused))int st)
{
	char *var = ".simple_shell_history";
	FILE *fn;
	char *arr = NULL;
	size_t flag = 0;
	int value = 0;
	char *as;

	fn = fopen(var, "r");
	if (fn == NULL)
	{
		return (-1);
	}
	while ((getline(&arr, &flag, fn)) != -1)
	{
		value++;
		as = _itoa(value);
		PRINT(as);
		write(as);
		PRINT(" ");
		PRINT(arr);
	}
	if (arr)
		write(arr);
	fclose(fn);
	return (0);
}


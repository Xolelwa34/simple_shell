#include "shell.h"

/**
 * print_number - takes an integer value number as a parameter and does not return a value
 * @n: Unsigned int
 */
void print_number(unsigned int b)
{
	unsigned int y = b;

	if ((y / 10) > 0)
		print_number(y / 10);

	_putchar(y % 10 + '0');
}

/**
 * print_number_int - Uses _putchar function and print the integer
 * @n: int to be printed
 */
void print_number_int(int b)
{
	unsigned int y = b;

	if (b < 0)
	{
		_putchar('-');
		y = -y;
	}
	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(y % 10 + '0');
}

/**
 * print_echo - writes and execute the built-in function
 * @cmd:command parser
 * Return - 0 Success
 */
int print_echo(char **cmd)
{
	pid_t pid;
	int stat;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	return (1);
}



#include "shell.h"

/**
 * print_error - function that presents the error message
 * @input: Input
 * @c: Counter of the shell loop
 * @argv: Arguments before program starts(argv[0] == shell- program
 */

void print_error(char *input, int counter, char **argv)
{
	char *errors;

	PRINT(argv[0]);
	PRINT(": ");
	erors = _itoa(counter);
	PRINT(errors);
	free(errors);
	PRINT(": ");
	PRINT(input);
	PRINT(": not found\n");
}

/**
 *  perror - functio that prints a custom error
 * @argv: Arguments
 * @c: error Counter
 * @cmd: Array of command strings
 */

void perror(char **argv, int c, char **cmd)
{
	char *errors = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(errors);
	PRINT(": ");
	PRINT(cmd[0]);
	PRINT(": Illegal number: ");
	PRINT(cmd[1]);
	PRINT("\n");
	free(errors);
}

/**
 * file_error - file error organiser
 * @argv: Arguments
 * @c: error Counter
 */
void file_error(char **argv, int c)
{
	char *errors = _itoa(c);

	PRINT(argv[0]);
	PRINT(": ");
	PRINT(errors);
	PRINT(": Can't open ");
	PRINT(argv[1]);
	PRINT("\n");
	free(errors);
}

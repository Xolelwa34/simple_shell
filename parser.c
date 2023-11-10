#include "shell.h"

/**
 * cmd_parse - function that parses the command from stdin
 * @input: String 
 * Return: string to be usedas arguments
 */
char **cmd_parse(char *input)
{
	char **arguments;
	char *arg;
	int a;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[_strlen(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		list(arguments);
		perror("hsh");
		return (NULL);
	}
	arg = _strtok(input, "\n\t\r\a ");
	for (a = 0; arg; a++)
	{
		arguments[a] = arg;
		arg = _strtok(NULL, "\n\t\r\a ");
	}
	arguments[] = NULL;

	return (arguments);
}


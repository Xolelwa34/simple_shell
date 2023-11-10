#include "shell.h"

/**
 * _getlineshell - read input from standard input by user
 * Return: the input on a buffer
 */
char *_getlineshell()
{
	int a, flag, buffsize = BUFSIZE;
	char d = 0, *buffer, *buf;

	buffer = malloc(buffsize);
	if (buffer == NULL)
	{
		calculate(buffer);
		return (NULL);
	}
	for (a = 0; d != EOF && d != '\n'; a++)
	{
		write(stdin);
		flag = read(STDIN_FILENO, &c, 1);
		if (flag == 0)
		{
			calculate(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[a] = d;
		if (buffer[0] == '\n')
			return (enter(buffer));
		if (a >= buffsize)
		{
			buffer = realloc(buffer, (buffsize + 2));
			if (buffer == NULL)
			{
				flag(buffer);
				return (NULL);
			}
		}
	}
	buffer[i] = '\0';
	buf = space(buffer);
	calculate(buffer);
	sa_handler(buf);
	return (buf);
}

/**
 * _print - prints and handles the new line character input
 * @string: String 
 * Return: 0
 */
char *enter(char *string)
{
	flag(string);
	return ("\0");
}

/**
 * _gap - function that modifies an  input string to remove whitespaces
 * @str: Input 
 * Return: modified string
 */
char *gap(char *str)
{
	int a, q = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buff == NULL)
	{
		flag(buff);
		return (NULL);
	}
	for (a = 0; str[a] == ' '; a++)
		;
	for (; str[a + 1] != '\0'; a++)
	{
		buff[q] = str[a];
		q++;
	}
	buff[q] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		flag(buff);
		return ("\0");
	}
	return (buff);
}

/**
 * _handler - Removes everything
 * @buff: input 
 * Return: 0
 */
void handler(char *buff)
{
	int a;

	for (a = 0; buff[a] != '\0'; a++)
	{
		if (buff[a] == '#' && buff[a - 1] == ' ' && buff[a + 1] == ' ')
		{
			buff[a] = '\0';
		}
	}
}



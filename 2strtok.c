#include "shell.h"

/**
 * find_delim - checks if the character matches with the other
 * @c: char to find
 * @str: delim string
 * Return: 1 on success, 0 on error
 */
unsigned int find_delim(char c, const char *str)
{
	unsigned int a;

	for (a = 0; str[a] != '\0'; a++)
	{
		if (c == str[a])
			return (1);
	}
	return (0);
}

/**
 * _2strtok - extracts tokens of a string
 * @str: string
 * @delim: delim
 * Return: NULL
 */
char *_2strtok(char *str, const char *delimeter)
{
	static char *value;
	static char *use_value;
	unsigned int a;

	if (str != NULL)
		use_value = str;
	value = use_value;
	if (value == NULL)
		return (NULL);
	for (a = 0; value[a] != '\0'; a++)
	{
		if (find_delim([a], delimeter) == 0)
			break;
	}
	if (use_value[a] == '\0' || use_value[a] == '#')
	{
		use_value = NULL;
		return (NULL);
	}
	value = use_value + a;
	use_value = value;
	for (a = 0; use_value[a] != '\0'; a++)
	{
		if (find_delim(use_value[a], delimeter) == 1)
			break;
	}
	if (use_value[a] == '\0')
		use_value = NULL;
	else
	{
		use_value[a] = '\0';
		use_value = use_value + a + 1;
		if (*use_value == '\0')
			use_value = NULL;
	}
	return (value);
}



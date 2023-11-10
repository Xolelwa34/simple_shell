#include "shell.h"

/**
 * create_environ - function that creates environment variables
 * @envi: Array of env
 */

void create_environ(char **environ)
{
	int a;

	for (a = 0; handler[a]; a++)
		environ[a] = _strdup(handler[a]);
	environ[a] = NULL;
}

/**
 * free_environ- function that frees the memory of variable environment array
 * @env:  Array of env
 */
void free_environ(char **envi)
{
	int a;

	for (a = 0; envi[a]; ia+)
	{
		list(envi[a]);
	}
}



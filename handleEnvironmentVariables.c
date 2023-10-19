#include "Shell.h"

/**
 * handleEnvironmentVariables - Handles environment variables
 * @env_args: Pointer to environment variables
 * @no_of_args: Number of environment variables
 * Return: void
 */


void handleEnvironmentVariables(char **env_args, size_t no_of_args)
{
	if (!env_args[1])
		_printenv();

	deallocate(env_args, no_of_args);
}


/**
 * _printenv - Prints environment variables
 * Return: void
 */
void _printenv(void)
{
	int i = 1;

	for (; environ[i]; i++)
		printf("%s\n", environ[i]);
}


#include "Shell.h"

/**
 * handleBuiltIn - Handles built in arguments
 * @args: arguments
 * @no_of_args: Number of arguments
 * Return: a boolean
 */




bool handleBuiltIn(char **args, size_t no_of_args, char *buffer)
{
	if (_strcmp(args[0], "exit"))
	{	free(buffer);
		handleExit(args, no_of_args);
	}
	else if (_strcmp(args[0], "env") || _strcmp(args[0], "printenv"))
	{	free(buffer);
		handleEnvironmentVariables(args, no_of_args);
		return (true);
	}

	return (false);
}


#include "Shell.h"

/**
 * handleExit - Handles exit input commands.
 * @exit_args: vector
 * @no_of_args: Number of arguments
 * Return: void
 */


void handleExit(char **exit_args, size_t no_of_args)
{
	int exitStatus = EXIT_SUCCESS;

	if (exit_args[1])
		exitStatus = _atoi(exit_args[1]);

	deallocate(exit_args, no_of_args);

	exit(exitStatus);
}


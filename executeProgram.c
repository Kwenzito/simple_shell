#include "Shell.h"


/**
 * **execute -Runs executable files
 * @args: arguments
 * @no_of_args: Number of arguments
 * Return: integer
 */


int execute(char **args, int no_of_args)
{
	execve(args[0], args, NULL);

	deallocate(args, no_of_args);

	perror("Error execve");

	exit(EXIT_FAILURE);
}


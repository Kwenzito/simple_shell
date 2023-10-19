#include "Shell.h"

/**
 * *getCommand - Gets input Commands from the user
 * @buffer: Pointer to input commands from the user
 * @buffer_size: size of the input (bytes)
 * Return: input commands
 */

char *getCommand(char *buffer, size_t buffer_size)
{
	ssize_t bytes;


	while ((bytes = getline(&buffer, &buffer_size, stdin)) != -1)
	{

		if (bytes > 0 && buffer[bytes - 1] == '\n')
		{
			buffer[bytes - 1] = '\0';
			return (buffer);
		}
		else
		{
			perror("Error getline");
			exit(EXIT_FAILURE);
		}

	}

	free(buffer);
	exit(EXIT_FAILURE);

	return (NULL);
}


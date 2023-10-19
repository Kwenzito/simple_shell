#include "Shell.h"

/**
 * *_getenv - Returns environment variable corresponding...
 * to the in input key.
 * @value: Pointer to key
 * Return: a pointer to an array of environmentt variables, or NULL on failure
 */

char *_getenv(char *value)
{
	size_t length = _strlen(value);
	char **environmentVar = environ;

	while (*environmentVar)
	{
		if (_strcmp(*environmentVar, value) && (*environmentVar)[length] == '=')
		{

			return (&((*environmentVar)[length + 1]));
		}
	environmentVar++;
	}

	return (NULL);
}


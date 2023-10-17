#include "Shell.h"

/**
 * _strcmp - Checks if substring is in the main string.
 * @str: Pointer to characters in main string
 * @substr: Pointer to characters in substring
 * Return: boolean, true if strings are the same, false otherwise
 */

bool _strcmp(char *str, char *substr)
{
	int strlength = _strlen(str), substrlength = _strlen(substr);
	int end = strlength - substrlength + 1, i = 0, j = 0;

	for (; i < end; i++)
	{
		bool matchFound = true;

		for (; j < substrlength; j++)
		{
			if (substr[j] != str[i + j])
			{
				matchFound = false;
				break;
			}
		}

		if (matchFound)
			return (true);
	}

	return (false);
}

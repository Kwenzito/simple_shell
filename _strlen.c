#include "Shell.h"

/**
 * _strlen - Returns the length of a string
 * @str: Pointer to characters in string
 * Return: integer, length of string s
 */
int _strlen(char *str)
{
	int length = 0;

	while (*str++)
	{
		length++;
	}
	return (length);
}

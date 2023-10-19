#include "Shell.h"
/**
 * is_delimeter - Checks if a character is a delimeter..
 * @chr: character to check
 * @delimeter: Pointer to chosen delimeter
 * Return: integer value 1 if character is delimeter,0 otherwise
 */



int is_delimeter(char chr, char *delimeter)
{
	while (*delimeter)
		if (*delimeter++ == chr)
			return (1);
	return (0);
}

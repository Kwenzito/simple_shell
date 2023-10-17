#include "Shell.h"

/**
 * print - Prints a character to STDOUT
 * @str: pointer to character
 *Return: void
 */

void print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}


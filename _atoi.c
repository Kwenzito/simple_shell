#include "Shell.h"
/**
 * _atoi - Converts a string to an integer
 * @str: Pointer characters in string.
 * Return: integer value of string.
*/

int _atoi(char *str)
{
	int sign = 1, i = 0;
	unsigned int intval = 0;

	while (!(str[i] <= '9' && str[i] >= '0')
					&& str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] <= '9' && (str[i] >= '0'
					&& str[i] != '\0'))
	{
		intval = (intval * 10) + (str[i] - '0');
		i++;
	}
	intval *= sign;
	return (intval);
}

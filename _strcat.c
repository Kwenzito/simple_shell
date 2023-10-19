#include "Shell.h"


/**
 * _strcat - Concatenates three strings
 * @s1: Pointer to characters in first string
 * @s2: Pointer to characters in second string
 * @s3: Pointer to characters in third string
 * Return: pointer to concatenated string, NULL otherwise
 */


char *_strcat(char *s1, char *s2, char *s3)
{
	size_t s1len = strlen(s1);
	size_t s2len = strlen(s2);
	size_t s3len = strlen(s3);
	char *res = malloc(s1len + s2len + s3len + 1);

	if (res)
	{
		_memcpy(res, s1, s1len);
		_memcpy(res + s1len, s2, s2len);
		_memcpy(res + s1len + s2len, s3, s3len + 1);
	}

	return (res);
}

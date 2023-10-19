#include "Shell.h"

/**
 * *_memcpy - copies n characters from...
 *  memory area src to memory area dest.
 * @dest: destination memory area
 * @src: source memory area
 *Return: pointer to destination memory area
 */

void *_memcpy(void *dest, void *src, int n)
{
	char *chr_dest = (char *) dest;
	char *chr_src = (char *) src;
	int i = 0;

	if (!dest)
		return (NULL);

	for (; i < n; i++)
		chr_dest[i] = chr_src[i];

	return (dest);
}

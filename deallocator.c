#include "Shell.h"

/**
 * deallocate - Frees memory allocated in heap
 * @ptr: pointer to heap memory
 * @ptrlength: pointer length
 * Return: void
 */

void  deallocate(char **ptr, int ptrlength)
{
	int i = 0;

	for (; i < ptrlength; i++)
	{
		free(ptr[i]);
	}

	free(ptr);
}


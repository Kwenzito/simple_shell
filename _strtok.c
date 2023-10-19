#include "Shell.h"
/**
 * **_strtok - Seperates a string into parts.
 * @str: Pointer to string to split.
 * @delimeter: Delimeter seperating individual words in string.
 * @no_of_args: Number of words/argumnents in the string
 * Return: pointer to an array of strings, or NULL on failure
 */


char **_strtok(char *str, char *delimeter, size_t *no_of_args)
{
	int a, b, c, d, wordcount = 0;
	char **token;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!delimeter)
		delimeter = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delimeter(str[a], delimeter) &&
				(is_delimeter(str[a + 1], delimeter) || !str[a + 1]))
			wordcount++;
	if (wordcount == 0)
		return (NULL);
	token = malloc((1 + wordcount) * sizeof(char *));
	if (!token)
		return (NULL);
	for (a = 0, b = 0; b < wordcount; b++)
	{
		while (is_delimeter(str[a], delimeter))
			a++;
		c = 0;
		while (!is_delimeter(str[a + c], delimeter) &&
				str[a + c])
			c++;
		token[b] = malloc((c + 1) * sizeof(char));
		if (!token[b])
		{
			for (c = 0; c < b; c++)
				free(token[c]);
			free(token);
			return (NULL);
		}
		for (d = 0; d < c; d++)
			token[b][d] = str[a++];
		token[b][d] = 0;
	}
	token[b] = NULL;
	*no_of_args = wordcount;
	return (token);
}


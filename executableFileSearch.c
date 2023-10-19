#include "Shell.h"

/**
 * fileFound - Checks if executable file exits in given path
 * @filepath: Pointer to executable file path
 * @statusBuffer: Status buffer
 * Return: boolean true if exe found, false otherwise
 */


bool fileFound(char *filepath, struct stat *statusBuffer)
{
	if (stat(filepath, statusBuffer) == 0)
		return (true);

	return (false);
}



/**
 * *searchFile  - Searches fo executable file
 * @filepath: Pointer  executable file path
 * @statusBuffer: Pointer Status buffer
 * Return: boolean true if exe found, false otherwise
 */

char *searchFile(char *filepath, struct stat *statusBuffer)
{
	size_t index = 0, no_of_paths;
	char *currentPath = _getenv("PATH"), *pathList;
	char **tempPathList = _strtok(currentPath, ":", &no_of_paths);

	for (; index < no_of_paths; index++)
	{
		pathList = _strcat(tempPathList[index], "/", filepath);


		if (fileFound(pathList, statusBuffer))
		{

			deallocate(tempPathList, no_of_paths);
			return (pathList);
		}
		free(pathList);
	}
	deallocate(tempPathList, no_of_paths);

	return (NULL);

}



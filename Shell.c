#include "Shell.h"
#include <sys/wait.h>
/**
 * main - The program entry point
 * @argc: Number of arguments
 * @argv: arguments vector
 * Return: Integer 0 (Success);
 */
int main(int argc, char *argv[])
{
	char **args;
	char *buffer = NULL, *prompt = "", *delimeter = " ", *path = NULL;
	size_t no_of_args = 0, buffer_size = 0;
	bool input = false;
	struct stat statusbuffer;

	while (running(input))
	{
		input = isCommandLineInput();
		print(prompt);
		buffer = getCommand(buffer, buffer_size);
		args = _strtok(buffer, delimeter, &no_of_args);

		if (handleBuiltIn(args, no_of_args, buffer))
			continue;

		if (!fileFound(args[0], &statusbuffer))
		{
			path = searchFile(args[0], &statusbuffer);

			if (!path)
			{
				printf("%s: %d: ", argv[0], argc);
				deallocate(args, no_of_args);
				free(buffer);
				continue;
			}
			else
			{
				free(args[0]);
				args[0] = path;
			}
		}
		executeProgram(args, no_of_args);
		free(buffer);
	}
	return (0);
}
/**
 * isCommandLineInput - The function checks if the file descriptor
 * belongs to a terminal or command line prompt
 * Return: boolean true if fd belongs to command line, false otherwise
 */
bool isCommandLineInput(void)
{
	if (isatty(STDIN_FILENO) == 0)
		return (true);

	return (false);
}

/**
 * running - The function checks if condition to run program
 * is true
 * @input: condition for program to run
 * Return: boolean true if conditions  satisfied, false otherwise
 */
bool running(bool input)
{
	bool runprog = (true && !input);

	return (runprog);
}

/**
 * executeProgram - The function executes  program
 * @args: arguments
 * @no_of_args: number of arguments
 * Return: void
 */
void executeProgram(char **args, size_t no_of_args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Error (fork)");
		deallocate(args, no_of_args);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		execute(args, no_of_args);


	if (waitpid(pid, &status, 0) == -1)
	{
		printf("in");
		perror("Error (Wait)");
		deallocate(args, no_of_args);
		exit(EXIT_FAILURE);
	}
	deallocate(args, no_of_args);

}


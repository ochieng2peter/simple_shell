#include "main.h"

/**
 * execute_command - Executes a command entered by the user.
 * @command: The command to be executed.
 *
 * Return: None.
 */

void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)/* Child process */
	{
		char *args[MAX_ARGS_LENGTH];
		int i = 0;
		char *token;
		/* Tokenize the command string into arguments */
		token = strtok(command, " \t\n");

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " \t\n");
		}
		args[i] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
			printf("Exiting the shell...\n");
			_exit(EXIT_SUCCESS);
		}
		/* Execute the command */
		execvp(args[0], args);
		/* If execvp() returns, it means the command execution failed */
		perror("Command execution failed");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0) /* Forking error */
	{
		perror("Forking failed");
		exit(EXIT_FAILURE);
	}
	else
	{ /* Parent process */
		/* Wait for child process to complete */
		wait(&status);
	}
}

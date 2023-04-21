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

	if (pid == 0) /* Child process */
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
		/* Execute the command with arguments */
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
	{	/* Parent process */
		/* Wait for child process to complete */
		wait(&status);
	}
}

/**
 * main - Entry point
 * Return: 0 upon successful run
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{	/* Display prompt */
		printf("peter_trevor# ");
		fflush(stdout); /* Read user input */

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{	/* End of file (Ctrl+D) encountered, exit shell */
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		/* Remove trailing newline character */
		command[strcspn(command, "\n")] = '\0';
		/* Execute the command with arguments */
		execute_command(command);
	}
	return (0);
}

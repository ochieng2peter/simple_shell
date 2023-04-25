#include "main.h"

/**
 * my_strcmp - Compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return:The difference between the first pair of differing
 *              characters, or 0 if the strings are equal.
 */

int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

/**
 * execute_command - Executes a command entered by the user.
 * @command: The command to be executed.
 * @str_cmp: function pointer to my_strcmp
 * Return: None.
 */

void execute_command(char *command, int (*str_cmp)(const char *, const char *))
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
		if (str_cmp(args[0], "exit") == 0)
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
	{ /* Parent process - Wait for child process to complete */
		wait(&status);
	}
}

#include "main.h"

/**
 * my_strcmp - Compares two strings.
 * @str1: A pointer to a constant character string.
 * @str2: A pointer to a constant character string.
 * Return: An integer value that represents the lexicographical
 *		difference between @str1 and @str2.
 * If @str1 is greater than @str2, it returns a positive number.
 * If @str1 is less than @str2, it returns a negative number.
 * If @str1 is equal to @str2, it returns 0.
 */
int my_strcmp(const char *str1, const char *str2)
{
	int i = 0;

	if (str1 == NULL || str2 == NULL)
	{
	return (-1);
	}

	while (str1[i] != '\0' && str2[i] != '\0')
	{
	if (str1[i] != str2[i])
	{
	break;
	}
	i++;
	}

	return (str1[i] - str2[i]);
}

/**
 * print_env_and_exit - Prints the current environment variables
 * Return: None.
 */
void print_env_and_exit(void)
{
	print_env();
	exit(EXIT_SUCCESS);
}
/**
 * execute_exit_command - Exits the shell.
 * Return: None.
 */
void execute_exit_command(void)
{
	write(STDOUT_FILENO,
			"Exiting the shell...\n", sizeof("Exiting the shell...\n") - 1);
	exit(EXIT_SUCCESS);
}
/**
 * execute_shell_command - Executes a shell command.
 * @args: An array of command and its arguments.
 * Return: None.
 */
void execute_shell_command(char *args[])
{
	char *error_msg = "Command execution failed\n";

	if (execvp(args[0], args) == -1)
	{
	write(STDERR_FILENO, error_msg, strlen(error_msg));
	exit(EXIT_FAILURE);
	}
}
/**
 * execute_command - Executes a shell command.
 * @command: A string representing the command to execute.
 * @str_cmp: A function pointer to a string comparison function.
 * Return: None.
 */
void execute_command(char *command, int (*str_cmp)(const char *, const char *))
{
	pid_t pid;
	int status;
	char *args[MAX_ARGS_LENGTH];
	int i = 0;
	char *token;

	token = strtok(command, " \t\n");
	while (token != NULL)
	{
	args[i++] = token;
	token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	if (command[0] == '\0')
	{
	return;
	}
	if (str_cmp(args[0], "printenv") == 0)
	{
	print_env_and_exit();
	}
	if (str_cmp(args[0], "exit") == 0)
	{
	execute_exit_command();
	}
	if (str_cmp(args[0], "cd") == 0)
	{
	cd(args[1]);
	return;
	}
	pid = fork();

	if (pid == -1)
	{ /* Forking error */
	write(STDERR_FILENO, "Forking failed\n", sizeof("Forking failed\n"));
	exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{ /* Child process */
	execute_shell_command(args);
	}
	else
	{ /* Parent process - Wait for child process to complete */
	waitpid(pid, &status, 0);
	if (str_cmp(args[0], "printenv") == 0)
	{
	print_env();
	}
	}
}


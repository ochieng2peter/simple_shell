#include "main.h"
/**
 * print_env - Prints the current environment variables.
 * Return: None.
 */
void print_env(void)
{
	int i;
	char newline = '\n';
	char *env_var;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_var = environ[i];
		while (*env_var != '\0')
		{
			if (write(STDOUT_FILENO, env_var, 1) < 0)
			{
				perror("write failed");
				exit(EXIT_FAILURE);
			}
			env_var++;
		}
		if (write(STDOUT_FILENO, &newline, 1) < 0)
		{
			perror("write failed");
			exit(EXIT_FAILURE);
		}
	}
}


#include "main.h"

/**
 * main - Entry point
 * Return: 0 upon successful run
 */


int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	/* Add /usr/local/bin to the PATH variable */
	add_path_dir("/usr/local/bin");

	while (1)
	{	/* Display prompt */
		printf("peter_trevor# ");
		fflush(stdout);		/* Read user input */

		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{	/* End of file (Ctrl+D) encountered, exit shell */
			printf("\n");
			exit(EXIT_SUCCESS);
		}	/* Remove trailing newline character */
		command[strcspn(command, "\n")] = '\0';
		/* Execute the command */
		execute_command(command, my_strcmp);
		/* Handle the printenv command */
		if (strcmp(command, "printenv") == 0)
		{
			print_env();
		}
	}
	return (0);
}

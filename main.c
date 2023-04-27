#include "main.h"
/**
 * main - Entry point
 * Return: 0 upon successful run
 */
int main(void)
{
	ssize_t nread;
	char command[MAX_COMMAND_LENGTH];

	add_path_dir("/usr/local/bin");

	while (1)
	{
		char prompt[] = "peter_trevor# ";

		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
		fflush(stdout);
		nread = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);
		if (nread == -1)
		{ /* Error reading from stdin */
			char error_msg[] = "Error reading from stdin\n";

			write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
			exit(EXIT_FAILURE);
		}
		else if (nread == 0)
		{ /* End of file (Ctrl+D) encountered, exit shell */
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		command[strcspn(command, "\n")] = '\0';
		execute_command(command, my_strcmp);
		if (my_strcmp(command, "printenv") == 0)
		{
			print_env();
		}
	}
	return (0);
}

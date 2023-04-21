#include "main.h"
/**
 * add_path_dir - Adds a new directory to the
 *      system's PATH environment variable
 * @dir: The path to the directory to be added
 * Return: Nothing.
*/
void add_path_dir(const char *dir)
{
	char path[MAX_PATH_LENGTH];
	char *new_path;
	const char *path_env = getenv("PATH");
	size_t path_len = strlen(path_env);
	size_t dir_len = strlen(dir);

	/* Get the current value of PATH */
	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set\n");
		exit(EXIT_FAILURE);
	}
	/* Copy the current value of PATH to a local buffer */
	if (path_len >= MAX_PATH_LENGTH - 1)
	{
		fprintf(stderr, "Error: PATH environment variable is too long\n");
		exit(EXIT_FAILURE);
	}
	strcpy(path, path_env);
	/* Append the new directory to the local buffer */
	if (path_len + dir_len + 2 >= MAX_PATH_LENGTH)
	{
		fprintf(stderr, "Error: Path is too long to add directory\n");
		exit(EXIT_FAILURE);
	}
	strncat(path, ":", MAX_PATH_LENGTH - 1 - path_len);
	strncat(path, dir, MAX_PATH_LENGTH - 1 - path_len - 1);
	/* Set the modified value of PATH in the environment */
	new_path = strdup(path);
	if (new_path == NULL)
	{
		perror("Error: strdup() failed");
		exit(EXIT_FAILURE);
	}
	setenv("PATH", new_path, 1);
	free(new_path);
}

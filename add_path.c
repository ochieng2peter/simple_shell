#include "main.h"
/**
 * add_path_dir - Adds a new dir to systm's PATH envir var
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

	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set\n");
		exit(EXIT_FAILURE);
	}
	if (path_len >= MAX_PATH_LENGTH - 1)
	{
		fprintf(stderr, "Error: PATH environment variable is too long\n");
		exit(EXIT_FAILURE);
	}
	strcpy(path, path_env);
	if (path_len + dir_len + 2 >= MAX_PATH_LENGTH)
	{
		fprintf(stderr, "Error: Path is too long to add directory\n");
		exit(EXIT_FAILURE);
	}
	strncat(path, ":", MAX_PATH_LENGTH - 1 - path_len);
	strncat(path, dir, MAX_PATH_LENGTH - 1 - path_len - 1);
	new_path = strdup(path);
	if (new_path == NULL)
	{
		perror("Error: strdup() failed");
		exit(EXIT_FAILURE);
	}
	setenv("PATH", new_path, 1);
	free(new_path);
}

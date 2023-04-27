#include "main.h"
/**
 * cd - Changes the current working directory.
 * @path: A string representing the new path.
 * If path is NULL or "~", change to home directory.
 * If path is "-", change to previous directory.
 * Return: None.
 */

void cd(char *path)
{
	if (path == NULL || strcmp(path, "~") == 0)
	{
		path = getenv("HOME");
	}
	else if (strcmp(path, "-") == 0)
	{
		path = getenv("OLDPWD");
	}
	if (chdir(path) == -1)
	{
		perror("cd");
		return;
	}
	else
	{
		char cwd[1024];

		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("getcwd");
			exit(EXIT_FAILURE);
		}
		else
		{
			setenv("OLDPWD", getenv("PWD"), 1);
			setenv("PWD", cwd, 1);
		}
	}
}

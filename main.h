#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS_LENGTH 50 
#define MAX_PATH_LENGTH 1000


extern char **environ;

/*functions*/

void execute_command(char *command, int (*str_cmp)(const char *, const char *));
void add_path_dir(const char *dir);
int my_strcmp(const char *s1, const char *s2);
void print_env(void);
void cd(char *path);

/*char *_getenv(const char *name, char **env);*/

#endif /* MAIN_H */

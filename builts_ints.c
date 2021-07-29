#include "holberton.h"
/**
* find_built_in_3 - find builts in
* @args: arguments
* @env: environment variables
* @buffer: user buffer
* Return: result 0 or -1
*/
int find_built_in_3(char **args, char **env, char *buffer)
{
	int i = 0;

	built_in functions[] = {
		{"exit", fexit},
		/*{"help", fhelp},*/
		{"cd", fcd},
		{"env", fenv},
		{NULL, NULL}
	};
	while (functions[i].name != NULL)
	{
		if (_strcmp(args[0], functions[i].name) == 0)
		{
			if (functions[i].f(args, env, buffer) == -1)
			{
				return (-1);
			}
			return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}
/**
* fexit - command exit function
* @args: arguments
* @env: environment variables
* @buffer: user buffer
* Return: result...
*/
int fexit(char **args, char **env, char *buffer)
{
	(void)env;

	free(buffer);
	free(args);
	exit(0);
}
/**
* fcd - command cd function
* @args: arguments
* @env: environment variables
* @buffer: user buffer
* Return: result 0
*/
int fcd(char **args, char **env, char *buffer)
{
	char *path = "HOME=";
	char *tmp = NULL;
	char *newdir = NULL;
	char *newdir1 = NULL;
	int i, j, k;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (path[j] != env[i][j])
			{
				break;
			}
		}
		if (j == 5)
			break;
	}
	tmp = malloc(_strlen(env[i]) - 4);
	if (tmp == NULL)
		exit(98);
	for (k = 0, j = 5; env[i][j] != '\0'; j++, k++)
		tmp[k] = 'a';
	for (k = 0, j = 5; env[i][j] != '\0'; j++, k++)
		tmp[k] = env[i][j];
	tmp[k] = '\0';

	if (args[1])
	{
		newdir = str_concat(tmp, "/");
		free(tmp);
		newdir1 = str_concat(newdir, args[1]);
		free(newdir);
		if (chdir(newdir1) != 0)
		{
			perror("");
		}
		free(newdir1);
	}
	else
	{
		if (chdir(tmp) != 0)
			perror("");
		free(tmp);
	}
	free(buffer);
	free(args);
	return (0);
}

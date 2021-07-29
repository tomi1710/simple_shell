#include "holberton.h"

static int flag;

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
	char *tmp = NULL, *oldpwd = NULL;
	char *newdir = NULL, *newdir1 = NULL;
	char my_cwdd[1024];

	getcwd(my_cwdd, 1024);

	tmp = look_env("HOME=", env);

	if (args[1] && args[1][0] == '.' && args[1][1] == '.')
	{
		_chdir(tmp);
	}
	else if (args[1] && args[1][0] == '/')
	{
		_chdir(args[1]);
	}
	else if (args[1] && args[1][0] == '-' && args[0][1] != '-')
	{
		oldpwd = look_env("OLDPWD=", env);
		printf("%s\n", oldpwd);
		if (oldpwd[0] == '\0')
			_chdir(my_cwdd);
		else
			_chdir(oldpwd);
		free(oldpwd);
	}
	else if (args[1])
	{
		newdir = str_concat(tmp, "/");
		newdir1 = str_concat(newdir, args[1]);
		free(newdir);
		_chdir(newdir1);
		free(newdir1);
	}
	else
	{
		if (flag == 1)
		{
			if (chdir(".") != 0)
				perror("");
		}
		else
			_chdir(tmp);
	}

	free(tmp);
	free(buffer);
	free(args);
	return (0);
}

char *look_env(char *path, char **env)
{
	int i, j, k;
	char *tmp = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < _strlen(path); j++)
		{
			if (path[j] != env[i][j])
			{
				break;
			}
		}

		if (env[i][5] == '\0' && j == 5)
		{
			flag = 1;
		}
		if (j == _strlen(path))
			break;
	}

	tmp = malloc(_strlen(env[i]) + 100);
	if (tmp == NULL)
		exit(98);

	for (k = 0, j = _strlen(path); env[i][j] != '\0'; j++, k++)
		tmp[k] = 'a';
	for (k = 0, j = _strlen(path); env[i][j] != '\0'; j++, k++)
		tmp[k] = env[i][j];
	tmp[k] = '\0';

	return (tmp);
}

void _chdir(char *dir)
{
	char my_cwd[1024];

	getcwd(my_cwd, 1024);
	setenv("OLDPWD", my_cwd, 1);

	if (chdir(dir) != 0)
		perror("");
	else
	{
		getcwd(my_cwd, 1024);
		setenv("PWD", dir, 1);
	}
}

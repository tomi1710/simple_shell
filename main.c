#include "holberton.h"
/**
 * main - Entry point
 * @ac: ac
 * @av: av
 * @env: environment variables
 * Return: void;
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	char **args = NULL;
	char *path = NULL;
	int built_in = 0;
	(void)ac;
	(void)av;

	signal(SIGINT, controlcfun);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			prompt_0();
		}
		buffer = getline_1();
		if (space_check(buffer) != 0 && buffer[0] != '\0')
		{
			args = split_line_2(buffer);
			built_in = find_built_in_3(args, env, buffer);
			if (built_in == 0)
			{
				continue;
			}
			if (main_extension(args, path, buffer, env) == 1)
				continue;
			free(buffer);
		}
		else
		{
			free(buffer);
			continue;
		}
	}
	return (0);
}

/**
 * main_extension - extension for the main function
 * @args: arguments from the main
 * @path: command path
 * @buffer: user buffer
 * @env: environment variables
 * Return: 0 on succes, 1 on failure.
 */
int main_extension(char **args, char *path, char *buffer, char **env)
{
	struct stat st;

	if (stat(args[0], &st) != 0)
	{
		path = getpath_4(args[0], env);
		if (path == NULL)
		{
			free(buffer);
			free(args);
			return (1);
		}
	}
	else
	{
		if (dir_check(args[0]) == 1)
		{
			free(buffer);
			free(args);
			free(path);
			return (1);
		}
	}
	execute_5(path, args, env);
	free(path);
	free(args);
	return (0);
}

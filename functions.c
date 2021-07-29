#include "holberton.h"
/**
 * prompt_0 - execute prompt
 *
 * Return: void
 */
void prompt_0(void)
{
	write(1, "$ ", 3);
}

/**
 * getline_1 - get line from user
 *
 * Return: buffer
 */
char *getline_1()
{
	int len = 0;
	size_t buffsize = 0;
	char *buffer = NULL;

	len = getline(&buffer, &buffsize, stdin);
	if (len == -1)
	{
		if (len == EOF)
		{
			free(buffer);
			exit(0);
		}
		perror("");
	}
	buffer[len - 1] = '\0';
	return (buffer);
}

/**
 * split_line_2 - separates command line
 * @buffer: buffer received from getline.
 * Return: tokens array;
 */
char **split_line_2(char *buffer)
{
	unsigned int bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		perror("Error: ");
		return (NULL);
	}
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		if (_strcmp(token, " ") != 0)
			tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = _realloc(tokens, (bufsize - 64) * sizeof(char *),
			bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("Error");
				return (NULL);
			}
		}
		token = strtok(NULL, " ");
	}
	free(token);
	tokens[i] = NULL;
	return (tokens);
}

/**
 * getpath_4 - function that finds specific command
 * @str: path line as string
 * @env: environment variable
 * Return: cat or NULL;
 */
char *getpath_4(char *str, char **env)
{
	int res = 0;
	int xd = 0;
	char *cat = NULL, *barra = "/";
	char *tkn = NULL;
	char *path = NULL;
	struct stat st;

	path = find_path(env);
	if (path[6] == '\0')
	{
		perror("");
		free(path);
		free(tkn);
		return (NULL);
	}
	strtok(path, "=");
	tkn = strtok(NULL, ":");
	while (tkn != NULL)
	{
		tkn = str_concat(tkn, barra);
		cat = str_concat(tkn, str);
		res = stat(cat, &st);
		if (res == 0)
		{
			free(tkn);
			free(path);
			return (cat);
		}
		else
		{
			free(tkn);
			free(cat);
		}
		tkn = strtok(NULL, ":");
	}
	xd = _strlen(str);
	write(1, "./hsh: 1: ", 10), write(1, str, xd), write(1, ": not found\n", 12);
	free(tkn);
	free(path);
	return (NULL);
}

/**
 * execute_5 - function that finds specific command
 * @path: path line as string
 * @args: user input
 * @env: environment variables
 * Return: void;
 */
void execute_5(char *path, char **args, char **env)
{
	pid_t child_pid = 0;
	int status;

	child_pid = fork();
		if (child_pid == -1)
			perror("");
		if (child_pid == 0)
		{
			if (execve(args[0], args, env) == -1)
			{
				if (execve(path, args, env) == -1)
				{
					free(path);
					exit(0);
				}
			}
		}
		else
		{
			wait(&status);
		}
}

#include "shell.h"

/**
 * main - main function of the shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *input = NULL, **tokens = NULL;
	int status, ex, tty = 1;
	size_t n;
	pid_t child;

	tty = isatty(0);
	while (1)
	{
		child = fork();
		if (child == -1)
		{
			perror("");
			exit(errno);
		}
		if (child == 0)
		{
			if (isatty(0))
				write(1, "$ ", 3);
			getline(&input, &n, stdin);
			tokens = _getinput(input, n);
			tokens[0] = checkexec(tokens[0]);
			free(input);
			if (execve(tokens[0], tokens, environ) == -1)
			{
				perror("");
				free(tokens);
				exit(errno);
			}
		}
		else
		{
			wait(&status);
			if (tty == 0 || WEXITSTATUS(status) == 98)
				return (ex);
		}
		if (WIFEXITED(status))
			ex = WEXITSTATUS(status);
	}
	return (0);
}

/**
 * _getinput - separes the imput in tokens
 *
 * @input: input
 * @size: size of the input
 * Return: pointer to array of strings
 */

char **_getinput(char *input, size_t size)
{
	char **tokens;
	int a = 0, b;
	char *buff;

	tokens = malloc(sizeof(char) * size);
	if (tokens == NULL)
	{
		perror("");
		exit(errno);
	}
	buff = strtok(input, " \n");
	b = checkbin(input, tokens);
	if (b == 0)
	{
		exit(99);
		perror("");
	}
	if (b == 1)
	{
		exit(98);
		perror("");
	}
	while (buff != NULL)
	{
		b = _strlen(buff);
		tokens[a] = malloc(sizeof(char) * b + 1);
		_strcpy(tokens[a], buff);
		buff = NULL;
		buff = strtok(NULL, " \n");
		a++;
	}
	return (tokens);
}

/**
 * checkexec - checks for an executable file
 *
 * @file: Name of the file to search
 * Return: directory of the file
 */

char *checkexec(char *file)
{
	char *buff = NULL, *buff2 = NULL, *buff3 = NULL, PATH[] = "PATH";
	int a = 0, b = 0, test = 0;
	struct stat st;

	if (stat(file, &st) == 0)
		return (file);
	buff3 = _strcon("/", file);
	while (environ[a] != NULL)
	{
		for (b = 0; environ[a][b] != '='; b++)
			{
			}
		buff = malloc(sizeof(char) * b + 1);
		for (b = 0; environ[a][b] != '='; b++)
			buff[b] = environ[a][b];
		buff[b] = '\0';
		if (_strcmp(buff, PATH) == 0)
		{
			free(buff);
			break;
		}
		free(buff);
		a++;
	}
	b = _strlen(environ[a]);
	buff = malloc(sizeof(char) * b + 1);
	_strcpy(buff, environ[a]);
	strtok(buff, "=");
	buff2 = strtok(NULL, ":");
	while (buff2 != NULL)
	{
		buff2 = _strcon(buff2, buff3);
		test = stat(buff2, &st);
		if (test == 0)
		{
			free(file), free(buff), free(buff3);
			return (buff2);
		}
		free(buff2);
		buff2 = strtok(NULL, ":");
	}
	perror("");
	free(file), free(buff), free(buff3), exit(127);
	return (NULL);
}

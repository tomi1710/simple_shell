#include "shell.h"

/**
 * main - main function of the shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *input = NULL, **tokens;
	int status, a = 0, ex;
	size_t n;
	pid_t child;

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
			write(1, "$ ", 2);
			getline(&input, &n, stdin);
			tokens = _getinput(input, n);
			while (tokens[a] != NULL)
				a++;
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
			if (WEXITSTATUS(status) == 98)
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
		tokens[a] = malloc(sizeof(char) * b);
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
	char *buff, *buff2, *buff3, PATH[] = "PATH";
	int a = 0, b, test;
	struct stat st;

	if (stat(file, &st) == 0)
		return (file);
	buff3 = _strcon("/", file);
	while (environ[a] != NULL)
	{
		buff = malloc(sizeof(char) * 20);
		for (b = 0; environ[a][b] != '='; b++)
			buff[b] = environ[a][b];
		if (_strcmp(buff, PATH) == 0)
		{
			free(buff);
			break;
		}
		free(buff);
		a++;
	}
	b = _strlen(environ[a]);
	buff = malloc(sizeof(char) * b);
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
	exit(127);
	free(file), free(buff), free(buff3);
	return (NULL);
}

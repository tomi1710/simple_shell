#include "shell.h"

/**
 * main - main function of the shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *input = NULL;
	int status, a = 0;
	size_t n;
	pid_t child;
	char **tokens;

	while (1)
	{
		child = fork();
		if (child == -1)
		{
			perror("");
			exit(98);
		}
		if (child == 0)
		{
			if (isatty(1) == 1)
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
				exit(99);
			}
		}
		else
		{
			wait(&status);
			if (status == 25088)
				exit(0);
		}
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
	int a = 0, b, len;
	char *buff, nl = '\n';

	tokens = malloc(sizeof(char) * size);
	buff = strtok(input, " \n");
	if (_strcmp(buff, "exit") == 0)
	{
		free(tokens);
		free(input);
		exit(98);
	}
	if (_strcmp(buff, "env") == 0)
	{
		free(input);
		free(tokens);
		for (b = 0; environ[b] != NULL; b++)
		{
			len = _strlen(environ[b]);
			write(1, environ[b], len);
			write(1, &nl, 1);
		}
		exit(99);
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
	int a = 0, b;
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
		if (stat(buff2, &st) == 0)
		{
			free(file), free(buff), free(buff3);
			return (buff2);
		}
		free(buff2);
		buff2 = strtok(NULL, ":");
	}
	free(file), free(buff), free(buff3);
	return (NULL);
}

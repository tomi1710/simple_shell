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

	while (1 < 2)
	{
		printf("Fork\n");
		child = fork();
		if (child == -1)
		{
			write(2, "Error", 6);
			exit(98);
		}
		if (child == 0)
		{
			write(1, "$ ", 2);
			getline(&input, &n, stdin);
			printf("Getinput %s %lu\n", input, n);
			tokens = _getinput(input, n);
			while (tokens[a] != NULL)
			{
				printf("%s\n", tokens[a]);
				a++;
			}
			tokens[0] = checkexec(tokens[0]);
			printf("execute\n");
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				printf("Error executing\n");
				a = 0;
				while (tokens[a] != NULL)
				{
					free(tokens[a]);
				}
				free(tokens);
			}
		}
		else
		{
			wait(&status);
			free(input);
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
	int a = 0, b;
	char *buff;

	printf("Open input\n");
	tokens = malloc(sizeof(char) * size);
	buff = strtok(input, " \n");
	while (buff != NULL)
	{
		printf("Enter loop\n");
		b = _strlen(buff);
		printf("b = %d\n", b);
		tokens[a] = malloc(sizeof(char) * b);
		_strcpy(tokens[a], buff);
		printf("token[%d] = %s\n", a, tokens[a]);
		buff = NULL;
		buff = strtok(NULL, " \n");
		a++;
	}
	tokens[a] = NULL;
	printf("Exit loop\n");
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
	char *buff, *buff2, PATH[] = "PATH";
	int a = 0, b;
	struct stat st;

	if (stat(file, &st) == 0)
		return (file);
	file = _strcon("/", file);
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
		buff2 = _strcon(buff2, file);
		if (stat(buff2, &st) == 0)
		{
			free(file), free(buff);
			return (buff2);
		}
		free(buff2);
		buff2 = strtok(NULL, ":");
	}
	write(2, "No executable found", 20);
	free(file), free(buff);
	return (NULL);
}

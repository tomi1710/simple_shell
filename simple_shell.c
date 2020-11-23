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
				exit(98);
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
        extern char **environ;
        char *buff, PATH = "PATH";
        int a = 0, b, c;

        if (stat(file) == 0)
        {
                return (file);
        }
        while (environ[a] != NULL)                                                                                              {
                buff = malloc(sizeof(char) * 20);
                while (environ[a][b] != '=')
                {
                        buff[b] = environ[a][b];
                }
                if (_strcmp(buff, PATH) == 0)
                {
                        break;
                }
                free(buff);
        }
        strtok(buff, "=");
        a = 0;
        PATH = strtok(NULL, ":");
        opendir(PATH);
        while (PATH != NULL)
	{
	}
}

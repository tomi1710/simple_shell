#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int mypid(void);
char* input(void);
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"", "/usr/", NULL};
	char *buffer, *exit = exit;
	int len;

	if (fork() == 0)
	{
		buffer = input();
		len = strlen(buffer);
		buffer[len - 1] = 0;
		argv[0] = buffer;
		printf("Before execve\n");

		if (execve(argv[0], argv, NULL) == -1)
		{
			printf("Error:");
		}
		printf("After execve\n");
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

char* input(void)
{
        char *buffer;
        size_t bufsize = 20;

        buffer = malloc(bufsize);

        printf("$ ");
        getline(&buffer, &bufsize, stdin);

        if (buffer == NULL)
        {
                printf("error allocating buffer\n");
                exit(1);
        }

        return (buffer);
}

/**
 * main - PID
 *
 * Return: Always 0.
 */
int mypid(void)
{
	pid_t my_pid;

	my_pid = getpid();
	return (my_pid);
}

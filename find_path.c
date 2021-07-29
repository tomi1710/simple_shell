#include "holberton.h"
/**
* find_path - search value of variable PATH
* @env: environ received
* Return: value of variable PATH
*/
char *find_path(char **env)
{
	char *path = NULL, *tmp = NULL;
	int i, len = 5;

	path = "PATH=";
	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(path, env[i], len) == 0)
		{
			break;
		}
	}
	if (env[i] != NULL)
	{
		tmp = malloc(_strlen(env[i]) + 1);
		if (tmp != NULL)
		{
			tmp = _strcpy(tmp, env[i]);
			return (tmp);
		}
		free(tmp);
	}
	return (NULL);

}
/**
* _strncmp - function to compare the first n characters of two strings
* @s1: string 1
* @s2: string 2
* @len: n characters to compare
* Return: value of variable PATH
*/
int _strncmp(char *s1, char *s2, int len)
{
	int a = 0;

	while (a < len)
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}

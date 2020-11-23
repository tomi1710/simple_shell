#include "shell.h"

/**
 * _strcpy - copy a string to destiny
 *
 * @dest: destiny to copy
 * @src: source string
 * Return: pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = src[a];
	return (dest);
}

/**
 * _strcon - concatenates two strings
 *
 * @dest: destiny string
 * @src: string to add
 * Return: pointer to dest
 */

char *_strcon(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++)
	{
	}
	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a + b] = src[b];
	}
	dest[a + b] = src[a];
	return (dest);
}

/**
 * _strcmp - compares two strings
 *
 * @str1: first string
 * @str2: second string
 * Return: 0 if ecuals, -1 if differents
 */

int _strcmp(char *str1, char *str2)
{
	int a = 0;
	for (; str1[a] == str2[a] && str1[a] != '\0' && str2[a] != '\0'; a++)
	{
	}
	return (str1[a] - str2[a]);
}

/**
 * _strlen - calculates the length of a string
 *
 * @str: string
 * Return: length of the string
 */

int _strlen(char *str)
{
	int a;

	for (a = 0; str[a] != '\0'; a++)
	{
	}
	return (a);
}

#include "holberton.h"
/**
 * _strlen - count the lenght of a string
 * @s: string
 * Return: len
 */
int _strlen(char *s)
{
	int n, len;

	n = len = 0;
	while (*(s + n) != '\0')
	{
		n++;
		len++;
	}
	return (len);
}

#include "holberton.h"
/**
 * str_concat - concatenates two strings.
 * @s1:  string 1
 * @s2: string 2
 * Return: pointer to str.
 */
char *str_concat(char *s1, char *s2)
{
	char *str;
	int a, b, size1, size2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	for (size1 = 0; *(s1 + size1) != '\0'; size1++)
	{
	}
	for (size2 = 0; *(s2 + size2) != '\0'; size2++)
	{
	}
	str = (char *)malloc(sizeof(char) * (size1 + size2) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	for (a = 0; a < size1; a++)
	{
		*(str + a) = *(s1 + a);
	}
	for (b = 0; b <= (size2); b++, a++)
	{
		*(str + a) = *(s2 + b);
	}
	return (str);
}

/**
 * _strcmp - Compares two strings
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Always 0 (Success)
 */
int _strcmp(char s1[], char s2[])
{
	int i = 0;
	int flag = 0;

	while (flag == 0)
	{
		if (s1[i] > s2[i])
		{
			flag = 1;
		}
		else if (s1[i] < s2[i])
		{
			flag = -1;
		}
		if (s1[i] == '\0')
		{
			break;
		}
		i++;
	}
	return (flag);
}

/**
 * _strcpy - Copies one string into another
 * @dest: String to be copied into
 * @src: String to be copied
 *
 * Return: Copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i, n;

	for (n = 0; *(src + n) != '\0'; n++)
	{
	}
	if (n != 0)
	{
		for (i = 0; i <= n; i++)
		{
			dest[i] = src[i];
		}
	}
	return (dest);
}

/**
 * _realloc - reallocate memory
 * @ptr: Pointer
 * @old_size: Old size
 * @new_size: New size to be allocated
 *
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (old_size == new_size)
	{
		return (ptr);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size < old_size)
	{
		free(ptr);
	}
	free(ptr);
	ptr = malloc(new_size);
	return (ptr);
}

/**
 * _strchr - check the code for Holberton School students.
 * @s: char pointer to be determined.
 * @c: char to compare.
 * Return: pointer or null.
 */
char *_strchr(char *s, char c)
{
	while (*s != c && *s != '\0')
	{
		s++;
	}
	if (*s == c)
	{
		return (s);
	}
	else
		return (0);
}

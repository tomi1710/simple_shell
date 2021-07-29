#include "holberton.h"
/**
* space_check - function to check if buffer contains only spaces.
* @buffer: user buffer.
*
* Return: 0 if only spaces, else 1.
*/
int space_check(char *buffer)
{
	int i, r = 0;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] != ' ')
		{
			r++;
			break;
		}
	}
	return (r);
}

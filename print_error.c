#include "holberton.h"
/**
* print_error - function to print an specific error.
* @str: command or file name.
* @error: error to print.
*
* Return: Nothing.
*/
void print_error(char *str, char *error)
{
	write(STDOUT_FILENO, str, _strlen(str));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, error, _strlen(error));
	write(STDOUT_FILENO, "\n", 1);
}

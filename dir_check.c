#include "holberton.h"
/**
* dir_check - function to check if directory exists.
* @dir_name: command or file name.
*
* Return: 1 on succes, 0 on failure.
*/
int dir_check(char *dir_name)
{
	DIR *dir = NULL;

	dir = opendir(dir_name);
	if (dir)
	{
		print_error(dir_name, "Is a directory");
		closedir(dir);
		return (1);
	}
	return (0);
}

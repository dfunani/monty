#include "monty.h"

/**
 * isFile - checks if a file can be read
 * @file_ptr: file
 *
 * Return: 0 - (success), 1 - (failure)
 */
int isFile(FILE *file_ptr)
{
	if (file_ptr == NULL)
		return (1);

	return (0);
}

/**
 * isInteger - checks if a string contains only digits
 * @str_value: string to validate
 *
 * Return: 0 - (success), 1 - (failure)
 */
int isInteger(char *str_value)
{
	if (!str_value)
		return (1);
	if (*str_value == '-')
		str_value++;

	while (*str_value)
	{
		if (*str_value >= '0' && *str_value <= '9')
			str_value++;
		else
			return (1);
	}

	return (0);
}

/**
 * isComment - checks if a line character starts with "#"
 * @tok: string to check for #
 *
 * Return: 0 - (Success), 1 - (Failure)
 */
int isComment(char *tok)
{
	if (tok && *tok == '#')
		return (0);

	return (1);
}

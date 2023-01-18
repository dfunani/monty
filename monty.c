#include "monty.h"

/**
 * main - main function for monty
 * @argc: integer number of arguments
 * @argv: command line arguments
 *
 * Return: 0 (success) 1 - (failure)
 */
int main(int argc, __attribute__((unused)) char **argv)
{
	FILE *file_ptr;
	char buff[1028], *token = NULL;
	stack_t *stack;
	unsigned int line_number = 0;

	stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_ptr = fopen(argv[1], "r");

	if (file_ptr)
	{
		while (fgets(buff, sizeof(buff), file_ptr) != NULL)
		{
			line_number++;
			token = strtok(buff, DELIMITER);
			if (!isComment(token) || !token)
				continue;
			exec_opcode(&stack, token, line_number);
		}
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fclose(file_ptr);
	deallocate(&stack);
	return (0);
}

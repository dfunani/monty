#include "main.h"

/**
 * main - Program Entry Point
 * @argc: Program arg count
 * @argv: Program args as a ptr to the char array (str)
 *
 * Return: an exit int (0 - successful)
 *
 */

int main(int argc, char **argv)
{
	FILE *monty;
	char buffer[1028];
	unsigned int line_num;

	if(argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty = fopen(argv[1], "r");
	if(!monty)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_num = 0;
	while(fgets(buffer, sizeof(buffer), monty))
	{
		line_num++;
		printf("%s", buffer);
	}
	return (0);
}

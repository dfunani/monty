#include "monty.h"

/**
 * exec_opcode - executes or finds the opcode
 * @stack: the stack
 * @tok: the string bearing the opcode
 * @ln: unsigned integer line number
 *
 * Return: void
 */
void exec_opcode(stack_t **stack, char *tok, unsigned int ln)
{
	instruction_t codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"mod", mod},
		{"div", divide},
		{NULL, NULL}};
		/**
		 * {"rot1", rot1},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", stack1},
		{NULL, NULL}};
		*/
	int i;

	for (i = 0; codes[i].opcode != NULL; i++)
	{
		if (!strcmp(codes[i].opcode, tok))
		{
			(codes[i].f)(stack, ln);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", ln, tok);
	deallocate(stack);
	exit(EXIT_FAILURE);
}

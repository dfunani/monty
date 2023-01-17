#include "main.h"

/**
 * check_ops - checks what ops is given in a token line
 * @stack: ptr to the stack (ref is passed in)
 * @token: ptr to the first sub string from strtok
 * @line_num: number indicating the line we are processing
 *
 */

int check_ops(stack_t **stack, char *token, unsigned int line_num)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	for(i = 0; ops[i].opcode != NULL; i++)
	{
		if(!strcmp(ops[i].opcode, token))
		{
			(ops[i].f)(stack, line_num);
			return (0);
		}
	}
	return (1);
}
#include "main.h"

/**
 * isNumber - check if a num is passed
 * @num: num to check
 *
 * return: 0 or 1
 *
 */

int isNumber(char *num)
{
	unsigned int i;

	for(i = 0; i < strlen(num); i++)
	{
		if(!isdigit(num[i]))
			return (0);
	}
	return (1);
}

/**
 * push - pushes to a stack obj
 * @stack: the stack obj to append
 * @line_number: the line number
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int stack_value;

	token = strtok(NULL, " \n\t\r");
	if(!token || !isNumber(token))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_value = atoi(token);
	if(stack)
		append_stack(stack, stack_value);
	else
		add_empty_stack(stack, stack_value);
}

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *head;

	head = *stack;
	if(head)
	{
		while(head)
		{
			printf("%d\n", head->n);
			head = head->next;
		}
	}
}

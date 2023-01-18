#include "monty.h"

/**
 * swap - swap last 2 elems
 * @stack: stack to swap ends
 * @line_number: ln
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	while ((*stack)->next->next)
		(*stack) = (*stack)->next;
	temp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = temp;
}

void add(stack_t __attribute__((unused)) **stack, unsigned int  __attribute__((unused)) line_number)
{
}

void nop(stack_t  __attribute__((unused)) **stack, unsigned int  __attribute__((unused)) line_number)
{
}

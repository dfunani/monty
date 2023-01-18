#include "monty.h"

/**
 * deallocate - frees up all memory
 * @stack: stack
 *
 * Return: void
 */
void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (*stack != NULL)
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		free(temp);
	}
}

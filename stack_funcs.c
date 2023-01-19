#include "monty.h"

/**
 * push - push/add a node to the stack.
 * @node: Pointer to the new node.
 * @line_number: token line number
 *
 */

void push(stack_t **node, __attribute__((unused))unsigned int line_number)
{
	stack_t *ptr;

	if (!node || !(*node))
		exit(EXIT_FAILURE);
	if (!stack)
	{
		stack = *node;
		return;
	}
	ptr = stack;
	stack = *node;
	stack->next = ptr;
	ptr->prev = stack;
}

/**
 * pall - print all elems in a stack.
 * @stack: ptr to the stack
 * @line_number: line number of the token
 *
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	ptr = *stack;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pop - remove top most element
 * @stack: stack to pop
 * @line_number: line num
 *
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = ptr->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(ptr);
}

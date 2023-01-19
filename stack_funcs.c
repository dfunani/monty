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

	if (node == NULL || (*node) == NULL)
		exit(EXIT_FAILURE);
	if (list == NULL)
	{
		list = *node;
		return;
	}
	ptr = list;
	list = *node;
	list->next = ptr;
	ptr->prev = list;
}

/**
 * pall - print all elems in a stack.
 * @stack: ptr to the stack
 * @line_number: line number of the token
 *
 */

void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *ptr;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	ptr = *stack;
	while (ptr != NULL)
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

	if (stack == NULL || (*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = ptr->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(ptr);
}

/**
 * pint - print top int
 * @stack: ptr to stack
 * @line_number: line num
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap - Swap top ints
 * @stack: ptr to stack
 * @line_number: l num
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	ptr = (*stack)->next;
	(*stack)->next = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = *stack;
	ptr->next = *stack;
	(*stack)->prev = ptr;
	ptr->prev = NULL;
	*stack = ptr;
}

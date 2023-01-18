#include "monty.h"

/**
 * push - adds a new element to the stack
 * @line_number: integer line number
 * @stack: the stack
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *next_token = strtok(NULL, DELIMITER);

	if (next_token == NULL || isInteger(next_token))
	{
		deallocate(stack);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(next_token);

	if (!(*stack) || !stack)
	{
		add_dnodeint(stack, value);
	}
	else
	{
		add_nodeint_end(stack, value);
	}
}

/**
 * pall - prints all the values on the stack starting from the top
 * @stack: stack
 * @line_number: interger line number
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!stack || !(*stack))
	{
		return;
	}

	print_dlist(*stack);
}

/**
 * pint - prints the top of the stack
 * @stack: stack
 * @line_number: integer line number
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *dlist = *stack;

	if (!stack || !(*stack))
	{
		deallocate(stack);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (dlist->next)
		dlist = dlist->next;

	printf("%d\n", dlist->n);
}

/**
 * pop - removes the element at the top of the stack
 * @stack: stack
 * @line_number: Error line number if any
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		deallocate(stack);
		fprintf(stderr, "L%u: can't pop an stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_end(stack);
}

/**
 * swap - swaps the top two elements
 * @stack: stack
 * @line_number: Error line number if any
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *dlist;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		deallocate(stack);
		exit(EXIT_FAILURE);
	}

	while (dlist->next->next)
	{
		dlist = dlist->next;
	}

	temp = dlist->next->n;
	dlist->next->n = dlist->n;
	dlist->n = temp;
}

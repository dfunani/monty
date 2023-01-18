#include "monty.h"

/**
 * add - adds the top two nodes of stack
 * @stack: stack
 * @line_number: unsigned int line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *dlist = *stack;
	int sum;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		deallocate(stack);
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (dlist->next->next)
		dlist = dlist->next;
	sum = dlist->n + dlist->next->n;
	pop(stack, line_number);
	pop(stack, line_number);

	if (!stack || !(*stack))
		add_dnodeint(stack, sum);
	else
		add_nodeint_end(stack, sum);
	free(dlist);
}

/**
 * sub - subtracts the top two nodes of stack
 * @stack: stack
 * @line_number: unsigned int line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *dlist = *stack;
	int result;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		deallocate(stack);
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (dlist->next->next)
		dlist = dlist->next;
	result = dlist->n - dlist->next->n;
	pop(stack, line_number);
	pop(stack, line_number);

	if (!stack || !(*stack))
		add_dnodeint(stack, result);
	else
		add_nodeint_end(stack, result);
	free(dlist);
}

/**
 * mul - multiplies the top two nodes of stack
 * @stack: stack
 * @line_number: unsigned int line number
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *dlist = *stack;
	int result;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		deallocate(stack);
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (dlist->next->next)
		dlist = dlist->next;
	result = dlist->n * dlist->next->n;
	pop(stack, line_number);
	pop(stack, line_number);

	if (!stack || !(*stack))
		add_dnodeint(stack, result);
	else
		add_nodeint_end(stack, result);
	free(dlist);
}

/**
 * divide - adds the top two nodes of stack
 * @stack: stack
 * @line_number: unsigned int line number
 *
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *dlist = *stack;
	int result;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		deallocate(stack);
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (dlist->next->next)
		dlist = dlist->next;

	if (dlist->next->n == 0)
	{
		deallocate(stack);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = dlist->n / dlist->next->n;
	pop(stack, line_number);
	pop(stack, line_number);

	if (!stack || !(*stack))
		add_dnodeint(stack, result);
	else
		add_nodeint_end(stack, result);
	free(dlist);
}

/**
 * mod - finds the remainder
 * @stack: stack
 * @line_number: unsigned int line number
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *dlist = *stack;
	int result;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		deallocate(stack);
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (dlist->next->next)
		dlist = dlist->next;

	if (dlist->next->n == 0)
	{
		deallocate(stack);
		fprintf(stderr, "L%u: L<line_number>: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = dlist->n % dlist->next->n;
	pop(stack, line_number);
	pop(stack, line_number);

	if (!stack || !(*stack))
		add_dnodeint(stack, result);
	else
		add_nodeint_end(stack, result);
	free(dlist);
}

#include "main.h"

/**
 * add_empty_stack - stack is epty append with node
 * @stack: ptr to the stack
 * @value: ptr to the val
 *
 * return: ptr to new stack
 *
 */

stack_t *add_empty_stack(stack_t **stack, int value)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if(!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = value;
	node->prev = NULL;
	node->next = *stack;
	if(*stack)
	{
		(*stack)->prev = node;
	}
	return (*stack);
}

stack_t *append_stack(stack_t **stack, int value)
{
	stack_t *node;
	stack_t *head;

	node = malloc(sizeof(stack_t));
	if(!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = value;
	node->prev = NULL;
	node->next = NULL;
	head = *stack;
	if(head)
	{
		while(head->next)
			head = head->next;
		node->prev = head;
		head->next = node;
		return (head);
	}
	*stack = node;
	return (node);
}

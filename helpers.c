#include "monty.h"

/**
 * free_nodes - Frees stack.
 */
void free_nodes(void)
{
	stack_t *ptr;

	if (!stack)
		return;

	while (stack)
	{
		ptr = stack;
		stack = stack->next;
		free(ptr);
	}
}

/**
 * add_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (stack == NULL)
	{
		stack = *new_node;
		return;
	}
	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}

#include "monty.h"

/**
 * print_dlist - prints the contents of a dlist
 * @h: list head
 *
 * Return: void
 */
void print_dlist(const stack_t *h)
{
	if (h != NULL)
	{
		while (h)
		{
			printf("%d\n", h->n);
			h = h->next;
		}
	}
}

/**
 * add_dnodeint - add a node
 * @head: double linked list head
 * @n: const integer
 *
 * Return: address of the new assignment
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
	{
		(*head)->prev = new;
	}

	*head = new;

	return (new);
}

/**
 * add_nodeint_end - adds a node to the end of a double list
 * @head: list head
 * @n: integer value
 *
 * Return: address of the new assignment
 */
stack_t *add_nodeint_end(stack_t **head, const int n)
{
	stack_t *new, *dlist;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (!head || !(*head))
	{
		*head = new;
		return (new);
	}

	dlist = *head;

	while (dlist->next)
		dlist = dlist->next;

	new->prev = dlist;
	dlist->next = new;

	return (new);
}

/**
 * delete_dnodeint_end - deletes a node at a given index value
 * @head: head of doubly linked list
 *
 * Return: address of the last node
 */
stack_t *delete_dnodeint_end(stack_t **head)
{
	stack_t *dlist = *head;

	if (!(*head))
		return (NULL);

	while (dlist->next)
		dlist = dlist->next;

	if (dlist->prev)
	{
		dlist->prev->next = NULL;
		dlist->prev = NULL;
	}
	else
	{
		*head = NULL;
		dlist->next = NULL;
		dlist->prev = NULL;
	}

	return (dlist);
}

/**
 * dlist_len - the length of the linked list
 * @head: the stack
 *
 * Return: integer length of stack
 */
int dlist_len(stack_t **head)
{
	int len = -1;
	stack_t *dlist = *head;

	if (dlist)
	{
		dlist = dlist->next;
		len++;
	}

	return (len);
}

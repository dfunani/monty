#include "monty.h"

stack_t *list = NULL;

/**
 * main - monty programs entry point
 * @argc: stdin args count
 * @argv: stdin args as string array
 *
 * Return: 0
 *
 */

int main(int argc, char **argv)
{
	FILE *file;
	int line_number;
	int isQueue;
	size_t max;
	char *monty;

	monty = NULL;
	max = 0;
	isQueue = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (argv[1] == NULL || file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_nodes();
		exit(EXIT_FAILURE);
	}
	for (line_number = 1; getline(&monty, &max, file) != -1; line_number++)
	{
		isQueue = monty_parser(monty, line_number, isQueue);
	}
	free(monty);
	fclose(file);
	return (0);
}

/**
 * monty_parser - parses a monty line into tokens to for evaluate the ops code
 * @monty: line from the file
 * @line_number: line number
 * @isQueue: Type of linked list - Queue or Stack
 *
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 *
 */

int monty_parser(char *monty, int line_number, int isQueue)
{
	char *opcode, *value;

	if (!monty)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_nodes();
		exit(EXIT_FAILURE);
	}
	opcode = strtok(monty, "\n ");
	if (opcode == NULL)
		return (isQueue);
	value = strtok(NULL, "\n ");
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	check_monty(opcode, value, line_number, isQueue);
	return (isQueue);
}

/**
 * check_monty - checks the token to determine which function to execute
 * @opcode: opcode
 * @value: argument of opcode
 * @isQueue: Linked list type
 * @ln: line number
 *
 */

void check_monty(char *opcode, char *value, int ln, int isQueue)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	flag = 1;
	for (i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			execute(func_list[i].f, opcode, value, ln, isQueue);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
		free_nodes();
		exit(EXIT_FAILURE);
	}
}


/**
 * execute - execute function.
 * @func: pointer to the function - of type global op_func
 * @op: token contains the opcode eg push, pall
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @isQueue: stack or queue
 *
 */
void execute(op_func func, char *op, char *val, int ln, int isQueue)
{
	stack_t *node;
	int neg;
	int i;

	neg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val++;
			neg = -1;
		}
		if (val == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			free_nodes();
			exit(EXIT_FAILURE);
		}
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n",
					ln);
				free_nodes();
				exit(EXIT_FAILURE);
			}
		}
		node = new_node(atoi(val) * neg);
		if (isQueue == 0)
			func(&node, ln);
		if (isQueue == 1)
			add_queue(&node, ln);
	}
	else
		func(&list, ln);
}

/**
 * free_nodes - Frees nodes in the stack.
 */

void free_nodes(void)
{
	stack_t *ptr;

	if (list == NULL)
		return;

	while (list != NULL)
	{
		ptr = list;
		list = list->next;
		free(ptr);
	}
}

#ifndef _MONTY_H
#define _MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *list;
typedef void (*op_func)(stack_t **, unsigned int);

/* Stack functions and operations */
void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);

/* Stack Arthemtic Operations */
void _add(stack_t **, unsigned int);
void _sub(stack_t **, unsigned int);
void _mul(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void _mod(stack_t **, unsigned int);

/* Helper functions */
void nop(stack_t **, unsigned int);
/* Default function - do nothing */
void free_nodes(void);
void add_queue(stack_t **, unsigned int);
stack_t *new_node(int n);
void execute(op_func, char *, char *, int, int);
void check_monty(char *, char*, int, int);
int monty_parser(char *, int, int);

/* String functions */
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

#endif

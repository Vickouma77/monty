#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


#define QUEUE 1
#define STACK 0
#define DELIM " \n\t\a\b"

/**
 * globales_s - struct with variable globals
 * @token2: integer
 * @fd: points to the previous element of the stack (or queue)
 * @line_buf: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globales_s
{
	char *token2;
	FILE *fd;
	char *line_buf;

} globales_t;

extern globales_t globalvar;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* main.c */
int main(int argc, char **argv);

/* node functions */
stack_t *create_node_stackfirst(stack_t **stack, int n);
stack_t *create_node_stackend(stack_t **stack, int n);
void free_node_stack(stack_t **stack);

/* get_builtin */
int get_builtin(char *token, stack_t **stack, unsigned int line_number);
/* builtins functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void div_m(stack_t **stack, unsigned int line_number);
void mod_m(stack_t **stack, unsigned int line_number);
void pstr_t(stack_t **stack, unsigned int line_number);
void rotrl(stack_t **stack, unsigned int line_number);





/*error*/
void stderr_usage(void);
void stderr_malloc(void);
void stderr_fopen(char *fd);
void stderr_int(unsigned int line_number);
void stderr_unknown(char *token, unsigned int line_number);
void div_e(unsigned int line_number);
void op_e(unsigned int line_number, char *op);
/* TEST F */

void tokerr(int error_code);
unsigned int array_len(void);
char *get_int(int num);
unsigned int abs_m(int);
int len_buff_uint(unsigned int num, unsigned int base);
void full_buff(unsigned int num, unsigned int base, char *buff, int buff_size);
void pop_e(unsigned int line_number);
void pint_e(unsigned int line_number);
void pchar_e(unsigned int line_number, char *msg);
int _isdigit();
void free_dlistint(stack_t *stack);
void free_globalvars(void);
void rotr(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint(stack_t **head, int n);

#endif

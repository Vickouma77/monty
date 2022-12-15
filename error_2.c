#include "monty.h"

/**
 * pop_e - pop error message for empty stacks.
 * @line_number: line number of the instructions.
 * Return: EXIT_FAILURE.
 */
void pop_e(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * pint_e - pint error message for empty stacks.
 * @line_number: line number of the instruction.
 * Return: EXIT_FAILURE
 */
void pint_e(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * op_e - math func error messagess.
 * @line_number: line number of the instruction.
 * @op: Operation where the error occurred.
 * Return: EXIT_FAILURE
 */
void op_e(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	free_globalvars();
	exit(EXIT_FAILURE);
}
/**
 * pchar_e - phar error msg for 0 stack & and non-char val.
 * @line_number: line number of the instruction
 * @msg: error message to print.
 * Return: EXIT_FAILURE.
 */
void pchar_e(unsigned int line_number, char *msg)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, msg);
	free_globalvars();
	exit(EXIT_FAILURE);
}

/**
 * div_e - error for div by 0.
 * @line_number: line number of the instruction.
 * Return: EXIT_FAILURE
 */
void div_e(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	free_globalvars();
	exit(EXIT_FAILURE);
}

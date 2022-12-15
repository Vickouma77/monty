#include "monty.h"

/**
 * get_builtin - Parses the instruction with the function.
 * @token: type pointer extern var char
 * @stack: type pointer node of data struct
 * @line_number: line of instructions
 * Return: Retunr the funtion
 */
int get_builtin(char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t op_built[] = {
		{ "push", push },
		{ "pall", pall},
		{ "pop", pop },
		{ "add", add },
		{ "nop", nop },
		{ "sub", sub },
		{ "pall", pall },
		{ "pint", pint },
		{ "swap", swap },
		{ "mul", mul },
		{ "div", div_m },
		{ "pchar", pchar },
		{ "mod", mod_m },
		{ "\n", nop },
		{ " ", nop },
		{ "\t", nop },
		{ "pstr", pstr_t },
		{ "rotl", rotrl },
		{ "rotr", rotr },
		{ NULL, NULL }
	};
	int i, flag = 0;
	char *argumentos = NULL;

	if (stack == NULL || token == NULL)
		return (0);
	argumentos = token;
	for (i = 0; op_built[i].opcode; i++)
	{
		if (strcmp(argumentos, op_built[i].opcode) == 0)
		{
			flag = 1;
			op_built[i].f(stack, line_number);
			break;
		}
	}
	if (flag == 0)
		stderr_unknown(token, line_number);
	return (0);
}

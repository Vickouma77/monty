#include "monty.h"

globales_t globalvar = {NULL, NULL, NULL};

/**
 * main - entry point for the CLI program
 * @argc: count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	char *token = NULL;
	size_t line_buf_size = 0;
	int line_number = 0, flag = 0, flag2 = 0;
	ssize_t line_size;
	stack_t *stack = NULL;

	if (argc != 2)
		stderr_usage();
	globalvar.fd = fopen(argv[1], "r");
	if (globalvar.fd == NULL)
		stderr_fopen(argv[1]);
	line_size = getline(&globalvar.line_buf, &line_buf_size, globalvar.fd);
	if (globalvar.line_buf[0] == '#')
		line_size = getline(&globalvar.line_buf, &line_buf_size, globalvar.fd);
	while (line_size >= 0)
	{flag = 0;
		flag2 = 0;
		line_number++;
		token = strtok(globalvar.line_buf, DELIM);
		globalvar.token2 = strtok(NULL, DELIM);
		if (token == NULL)
		{flag2 = 1;
			nop(&stack, line_number); }
		if (flag2 == 0)
		{
			if (token[0] == '#')
			{
				line_size = getline(&globalvar.line_buf,
						    &line_buf_size, globalvar.fd);
				flag = 1; }}
		if (flag == 0)
		{get_builtin(token, &stack, line_number);
			line_size = getline(&globalvar.line_buf, &line_buf_size,
					    globalvar.fd); }}
	free_dlistint(stack);
	free(globalvar.line_buf);
	globalvar.line_buf = NULL;
	fclose(globalvar.fd);
	return (EXIT_SUCCESS);
}

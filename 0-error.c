#include "monty.h"
/**
 * usage_error - printing an usage error messages
 * Return: FAILURE
 */

void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);

}

/**
 *open_error - printing an open file error messages
 *@file: file
 * Return: FAILURE
 */

void open_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);

	exit(EXIT_FAILURE);

}

/**
 * push_error - handling a push error
 * @fd: file desciptores
 * @line: bufferes
 * @stack:  stacks or queues
 * @line_number: lines numbers of the command
 */

void push_error(FILE *fd, char *line, stack_t *stack, int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	fclose(fd);
	free(line);
	_free(stack);
	exit(EXIT_FAILURE);
}

/**
 * instr_error - Errors handler for unknowns instructions
 * @fd: file descriptors
 * @line: buffers
 * @stack:  stacks or queues
 * @line_n: lines numbers of the command
 * @val: instructions
 */

void instr_error(FILE *fd, char *line, stack_t *stack, char *val, int line_n)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_n, val);
	fclose(fd);
	free(line);
	_free(stack);
	exit(EXIT_FAILURE);
}

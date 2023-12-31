#include "monty.h"

/**
 * divide -  divide the second top element of the stack
 * by the top element of the stacks
 * @stack: doubles pointers to the head of the stack
 * @line_number: the line numbers
 */

void divide(stack_t **stack, unsigned int line_number)
{

	stack_t *val = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

		if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}


	val = (*stack)->next;
	sum = val->n;
	sum /= (*stack)->n;
	pop(stack, line_number);
	val->n = sum;
}

/**
 * mul - multiplie the second top element of the stack with
 * the tops element of the stack.
 * @stack: doubles pointer to the head of the stack
 * @line_number: the lines number
 */

void mul(stack_t **stack, unsigned int line_number)
{

	stack_t *val = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	val = (*stack)->next;
	sum = val->n;
	sum *= (*stack)->n;
	pop(stack, line_number);
	val->n = sum;
}

/**
 * mod - compute the rest of the division of the second
 * top elements of the stack by the top element of the stack.
 * @stack: doubles pointer to the head of the stack
 * @line_number: the lines numbers
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *val = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}


	val = (*stack)->next;
	sum = val->n;
	sum %= (*stack)->n;
	pop(stack, line_number);
	val->n = sum;
}

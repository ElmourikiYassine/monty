#include "monty.h"

/**
 * sub - Subs the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = ((*stack)->next->n - (*stack)->n);
	/*
	(*stack)->next->n = ((*stack)->next->n > (*stack)->n) ?
		((*stack)->next->n - (*stack)->n) :
		((*stack)->n - (*stack)->next->n);
	*/
	pop(stack, line_number);
}


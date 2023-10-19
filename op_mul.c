#include "monty.h"

/**
 * mul - Mul the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}


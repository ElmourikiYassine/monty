#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the stack.
 * @line_number: The current line number (unused).
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		stack_t *top = *stack;
		stack_t *second = top->next;
		stack_t *last = *stack;

		while (last->next)
			last = last->next;

		top->next = last->next;
		top->prev = last;
		last->next = top;
		second->prev = NULL;
		*stack = second;
	}
}


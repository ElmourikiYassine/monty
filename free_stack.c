#include "monty.h"
/**
 * free_stack - frees the stack
 * @stack: the head
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp;

	tmp = *stack;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

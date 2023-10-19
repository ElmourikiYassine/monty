#include "monty.h"

/**
 * pstr - Print the elements as an ASCII.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	int found = 0;

	(void) line_number;
	if (!*stack)
	{
		printf("\n");
		return;
	}
	current = *stack;

	while (current->n != 0   &&
		current->n >= 33   &&
		current->n <= 126 &&
		current->next != NULL)
	{
		found = 1;
		printf("%c", current->n);
		current = current->next;
	}
	if (found)
		printf("\n");
}


#include "monty.h"

/**
 * pstr - Print the elements as an ASCII.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int found = 0;

	(void) line_number;
	if (!*stack)
	{
		printf("\n");
		return;
	}
	while (current->next != NULL &&
		current->n != 0      &&
		current->n > 0       &&
		current->n <= 126)
	{
		found = 1;
		printf("%c", current->n);
		current = current->next;
	}
	if (found)
		printf("\n");
}


#include "monty.h"

/**
 * pstr - Print the elements as an ASCII.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	current = *stack;
	while (current != NULL)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}


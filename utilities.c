#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (*stack == NULL)
	{
		new_node->n = line_number;
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{

		new_node->n = line_number;
		(*stack)->prev = new_node;
		new_node->next = *stack;
		new_node->prev = NULL;
		*stack = new_node;
	}
}


/**
 * pall - Prints all values on the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	(void) line_number;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


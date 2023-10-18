#define _GNU_SOURCE
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

/**
 * isNumber - Checks if a string represents a valid number.
 * @number: The input string to be checked.
 *
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int isNumber(char *number)
{
	int i = 0;

	if (number[0] == '-')
		i = 1;
	for (; number[i] != 0; i++)
	{
		if (!isdigit(number[i]))
			return (0);
	}
	return (1);
}

/**
 * execute_instruction - Executes a specific instruction.
 * @token: The instruction token.
 * @arg: The argument associated with the instruction.
 * @line_number: The current line number.
 * @stack: A pointer to the stack.
 * @file: A pointer to the stack.
 */
void execute_instruction(char *token, char *arg,
		unsigned int *line_number, stack_t **stack, FILE *file)
{
	int i = 0;
	int found = 0;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	while (instruction[i].opcode != NULL)
	{
		if (strcmp(token, instruction[i].opcode) == 0)
		{
			if (strcmp(token, "push") == 0)
			{
				if (arg == NULL || !isNumber(arg))
				{
					fprintf(stderr, "L%d: usage: push integer\n", *line_number);
					fclose(file);
					free_stack(stack);
					exit(EXIT_FAILURE);
				}
				instruction[i].f(stack, atoi(arg));
			}
			else
				instruction[i].f(stack, *line_number);
			found = 1;
			break;
		}
		i++;
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", *line_number, token);
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * process_line - Processes a line of input.
 * @line: The line to process.
 * @line_number: A pointer to the current line number.
 * @stack: A pointer to the current line number.
 * @file: A pointer to the current line number.
 */
void process_line(char *line, unsigned int *line_number,
		stack_t **stack, FILE *file)
{
	char *token, *arg, *line_cpy = strdup(line);

	if (!line_cpy)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	token = strtok(line_cpy, " \n\t\r");
	arg = strtok(NULL, " \n\t\r");

	execute_instruction(token, arg, line_number, stack, file);

	free(line_cpy);
}

/**
 * main - The entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, or an exit code on failure.
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t line_len;
	FILE *stream;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((line_len = getline(&line, &len, stream)) != -1)
	{
		char *line_cpy = strdup(line);
		char *token = strtok(line_cpy, " \n\t\r");

		if (!line_cpy)
		{
			fprintf(stderr, "Error: malloc failed\n");
			fclose(stream);
			free_stack(&stack);
			exit(EXIT_FAILURE);
		}
		if (line_len > 1 && token != NULL)
			process_line(line, &line_number, &stack, stream);
		line_number++;
		free(line_cpy);
	}
	fclose(stream);
	free(line);
	free_stack(&stack);
	return (0);
}


#define _GNU_SOURCE
#include "monty.h"

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
 * process_line - Processes a line of input.
 * @line: The line to process.
 * @line_number: A pointer to the current line number.
 * @stack: A pointer to the current line number.
 */
void process_line(char *line, unsigned int *line_number, stack_t **stack)
{
	int i = 0;
	char *token, *arg, *line_cpy = strdup(line);
	instruction_t instruction[] = {{"push", push}, {"pall", pall}, {NULL, NULL},
		{"pint", pint},
		{NULL, NULL}
	};

	if (!line_cpy)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line_cpy, " \n\t\r");
	while (instruction[i].opcode != NULL)
	{
		if (strcmp(token, instruction[i].opcode) == 0)
		{
			if (strcmp(token, "push") == 0)
			{
				arg = strtok(NULL, " \n\t\r");
				if (arg == NULL || !isNumber(arg))
				{
					free(line_cpy);
					fprintf(stderr, "L%d: usage: push integer\n", *line_number);
					exit(EXIT_FAILURE);
				}
				instruction[i].f(stack, atoi(arg));
			}
			else
				instruction[i].f(stack, *line_number);
			break;
		}
		i++;
	}
	if (instruction[i].opcode == NULL)
	{
		free(line_cpy);
		fprintf(stderr, "L%d: unknown instruction %s\n", *line_number, token);
		exit(EXIT_FAILURE);
	}
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
			exit(EXIT_FAILURE);
		}
		if (line_len > 1 && token != NULL)
			process_line(line, &line_number, &stack);
		line_number++;
		free(line_cpy);
	}

	fclose(stream);
	return (0);
}


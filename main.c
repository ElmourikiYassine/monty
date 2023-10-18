#define _GNU_SOURCE
#include "monty.h"

/**
 * process_line - Processes a line of input.
 * @line: The line to process.
 * @line_number: A pointer to the current line number.
 */
void process_line(char *line, unsigned int *line_number)
{
	int i = 0;
	char *token;
	char *line_cpy = strdup(line);
	stack_t **stack = NULL;
	instruction_t instruction[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	token = strtok(line_cpy, " \n\t\r");
	while (instruction[i].opcode != NULL)
	{
		if (strstr(token, instruction[i].opcode))
		{
			if (strstr(token, "push"))
				instruction[i].f(stack, atoi(strtok(NULL, " \n\t\r")));
			else
				instruction[i].f(stack, *line_number);
			printf("%s", line);
			break;
		}
		i++;
	}
	if (instruction[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", *line_number, token);
		free(line_cpy);
		exit(EXIT_FAILURE);
	}
	free(line_cpy);
	(*line_number)++;
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

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 19);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((line_len = getline(&line, &len, stream)) != -1)
	{
		process_line(line, &line_number);
	}

	fclose(stream);
	return (0);
}


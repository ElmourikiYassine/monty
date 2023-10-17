#define _GNU_SOURCE
#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("invoked\n");
}


void pall(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("invoked\n");
}
int main(int argc, char **argv)
{

	char *line = NULL;
	size_t len = 0;
	ssize_t line_len;
	FILE *stream;
	unsigned int line_number = 0;
	instruction_t instruction[] =
	{
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

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
		int i = 0;
		char *token;
		char *line_cpy = strdup(line);

		token = strtok(line_cpy, " \n\t\r");
		while (instruction[i].opcode != NULL)
		{
			if (strstr(token, instruction[i].opcode))
			{
				printf("%s <---\n", token);
			}
			i++;
		}
		printf("%s", line);
		free(line_cpy);
		line_number++;
	}
	return (0);
}


#include "monty.h"

instruction_t instruction[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"swap", swap},
	{"pop", pop},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", _div},
	{"mul", mul},
	{"mod", mod},
	{"#", nop},
	{"pchar", pchar},
	{"pstr", pstr},
	{"NULL", NULL}
};


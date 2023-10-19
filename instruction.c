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
<<<<<<< HEAD
	{"rotl", rotl},
=======
	{"pstr", pstr},
>>>>>>> b419fa60ebcb0fb50a0a53c4c8fd044b10dae40b
	{"NULL", NULL}
};


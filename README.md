# Monty Project

This repository contains the implementation of an interpreter for Monty ByteCodes files. Monty 0.98 is a scripting language that relies on a unique stack, with specific instructions to manipulate it.

## Data Structures

Please use the following data structures for this project. Include them in your header file.

```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Compilation & Output

Compile your code using the following command:

```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

Any output must be printed on `stdout`, and any error message must be printed on `stderr`. Make sure to handle errors as described in the project specifications.

## Tests

Work together on a set of tests to ensure the correctness of your implementation.

## Monty Language

Monty 0.98 is a scripting language compiled into Monty byte codes. The language relies on a unique stack with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty Byte Code Files

Files containing Monty byte codes usually have the `.m` extension. Each line contains one instruction. Blank lines and additional text after the opcode or its required argument are ignored.

Example:

```bash
push 0
push 1
push 2
pall
```

## The Monty Program

Usage: `monty file`

- If no file or more than one argument is given, print `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`.
- If unable to open the file, print `Error: Can't open file <file>`, followed by a new line, and exit with `EXIT_FAILURE`.
- If the file contains an invalid instruction, print `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with `EXIT_FAILURE`.
- If unable to allocate memory (malloc fails), print `Error: malloc failed`, followed by a new line, and exit with `EXIT_FAILURE`.

## Tasks

### Task 0: push, pall (mandatory)

Implement the `push` and `pall` opcodes as described in the project specifications.

### Task 1: pint (mandatory)

Implement the `pint` opcode as described in the project specifications.

### Task 2: pop (mandatory)

Implement the `pop` opcode as described in the project specifications.

### Task 3: swap (mandatory)

Implement the `swap` opcode as described in the project specifications.

### Task 4: add (mandatory)

Implement the `add` opcode as described in the project specifications.

### Task 5: nop (mandatory)

Implement the `nop` opcode as described in the project specifications.

### Task 6: sub (advanced)

Implement the `sub` opcode as described in the project specifications.

...

(Continue with the remaining tasks, following the same format)

## Quiz Questions

Answer the quiz questions to test your understanding of the project.

## Directory: bf (advanced)

### Task 16: Brainf*ck

Write a Brainf*ck script that prints "School" followed by a new line. The Brainf*ck files should be stored in the `bf` subdirectory.

Example:

```bash
$ bf bf/1000-school.bf
School
```

### Task 17: Add two digits (advanced)

Read two digits from stdin, add them, and print the result.

Example:

```bash
$ bf bf/1001-add.bf
81
9
```

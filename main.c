#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * execute_opcode - execute opcode
 * @opcode: opcode
 * @top: pointer to head
 * @counter: line number
 * Return: 0 or 1
 */
int execute_opcode(char *opcode, stack_t **top, unsigned int counter)
{
	int i = 0;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};
	while (opcodes[i].opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(top, counter);
			return (1);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
	return (0);
}

/**
 * free_stack - Free allocated memory
 * @top: Pointer to the stack
 * @line: Pointer to the line buffer
 * @file: Pointer to the file
 * Return: void
 */

void free_stack(stack_t **top, char *line, FILE *file)
{
	while (*top)
	{
		(*top) = (*top)->next;
		free(*top);
		*top = *top;
	}
	free(line);
	fclose(file);
}

/**
 * main - program entry
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1
 */

int main(int argc, char *argv[])
{
	stack_t *top = NULL;
	ssize_t read_line;
	FILE *file;
	size_t size = 0;
	char *line = NULL, *opcode;
	unsigned int line_num = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((read_line = getline(&line, &size, file)) != -1)
	{
		opcode = strtok(line, " \t\n");
		if (opcode)
		{
			if (!execute_opcode(opcode, &top, line_num))
			{
				free_stack(&top, line, file);
				return (EXIT_FAILURE);
			}
		}
		line_num++;
	}
	free_stack(&top, line, file);
	return (EXIT_SUCCESS);
}

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * main - program entry
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	ssize_t read_line;
	FILE *file;
	size_t size = 0;
	char *line, *opcode;
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
	while (read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &size, file);
		opcode = strtok(line, " \t\n");
		if (opcode)
		{
			if (strcmp(opcode, "push") == 0)
				push(&stack, line_num);
			else if (strcmp(opcode, "pall") == 0)
			{
				pall(&stack, line_num);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instructions %s", line_num, opcode);
				free(line);
				fclose(file);
				return (EXIT_FAILURE);
			}
		}
		line_num++;
	}
	free(line);
	fclose(file);
	return (0);

}

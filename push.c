#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
/**
 * push - Pushes an element onto the stack.
 * @top: Pointer to the head of the stack.
 * @counter: Line number in the Monty byte code file.
 * Return: void
 */
void push(stack_t **top, unsigned int counter)
{
	char *arg = strtok(NULL, " \t\n");
	int value;
	stack_t *new_node;

	if (!arg || (*arg != '-' && (*arg < '0' || *arg > '9')))
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *top;
	if (*top)
		(*top)->prev = new_node;
	*top = new_node;
}

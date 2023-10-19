#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * is_integer - checks if a str is an integer
 * @str: string
 * Return: 1 or 0
 */

int is_integer(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 * Return: vpoid
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n");
	int value;
	stack_t *new_node;

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%d: Usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
		new_node->next = NULL;
	*stack = new_node;
}

/**
 * pall - print all values on the stack
 * @stack: pointer to head
 * @line_number: line nu,ber
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}

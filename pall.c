#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
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

#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pall - a function that print all values on the stack
 * *stack: pointer to head
 * @line_number: line nu,ber
 * Return: void
 */
void pall(stackIsh **stack, unsigned int line_number)
{
	(void)line_number;

	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
}

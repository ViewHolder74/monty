#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pall - a function that print all values on the stack
 * *stack: pointer to head
 * @line_number: line nu,ber
 * Return: void
 */
void pall(stack_t **top, unsigned int counter)
{
	(void)counter;

	while (*top != NULL)
	{
		printf("%d\n", (*top)->n);
		*top = (*top)->next;
	}
}

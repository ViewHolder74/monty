#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * pall - a function that print all values on the stack
 * @top: pointer to head
 * @counter: line nu,ber
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

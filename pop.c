#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * pop - prints the top
 * @stack: stack head
 * @counter: line_number
 * Return: no return
*/
void pop(stack_t **stack, unsigned int counter)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = h->next;
	free(h);
}

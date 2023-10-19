#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add - Add the top two elements of the stack
 * @top: Pointer to the head of the stack
 * @counter: Line number in the Monty byte code file
 * Return: void
 */
void add(stack_t **top, unsigned int counter)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n += (*top)->n;
	pop(top, counter);
}


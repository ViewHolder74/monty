#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * pop - prints the top
 * @top: stack head
 * @counter: line_number
 * Return: no return
*/
void pop(stack_t **top, unsigned int counter)
{
	stack_t *temp;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		exit(EXIT_FAILURE);
	}
	temp = *top;
	*top = (*top)->next;
	if (*top)
		(*top)->prev = NULL;
	free(temp);
}

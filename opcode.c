#include "monty.h"
#include <stdio.h>

/**
 * pop: a function that removes element at the top of stack
 * @temp: temporary pointer to the top node
 * @next: the next node to be pointed to
 * Removes the element at the top, else print error
 */
void pop(stack **top)
{
	if (!*stack)
	{
		fprintf(stderr, "L<line_number>:cannot pop an empty stack/n");
		exit(EXIT_FAILURE);
	}
	else 
	{
		stack *temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}

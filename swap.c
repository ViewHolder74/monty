#include "monty.h"
#include <stdio.h>

/**
 * swap: function to swap two elements of the stack
 * @temp: temporary variable for value of top node
 * @next: the value next to the top element
 * *top: the element at the top
 * Returns swap of two elements at the top, else error
 */
void swap(stack **top)
{
	if (*top && (*top)->next)
	{
		int temp = (*top)->n;
		(*top)->n = (*top)->next->n;
		(*top)->next->n = temp;
	}
	else
	{
		fprintf(stderr, "L<line_number>:cannot swap, stack very short/n");
		exit(EXIT_FAILURE);
	}
}

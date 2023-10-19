#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * swap - adds the top two elements of the stack.
 * @stack: stack head
 * @counter: line_number
 * Return: no return
*/
void swap(stack_t **top, unsigned int counter)
{
	stack_t *h;
	int len = 0, curr;

	h = *top;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}
	h = *top;
	curr = h->n;
	h->n = h->next->n;
	h->next->n = curr;
}

#include "monty.h"
#include <string.h>

#define LIMIT 100

void push(int element, int line_num)
{
	int stack[LIMIT], top;

	if (top == LIMIT - 1)
	{
		fprintf(stderr, "L%d stack overflow\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack[++top] = element;
	}
}

void pull()
{
	int i, top, stack[LIMIT];

	for (i = top; i >= 0; i--)
		printf("%d\n", stack[i]);
}


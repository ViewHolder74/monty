#include monty.h

/**
*pint: a function that print value at the top of stack
*@top: the top of the stack
*@n: value at the top
*Returns value at the top pf stack else print error
*/
void pint(stack *top)
{
        if (!top)
        {
                fprintf(stderr, "L<line_number>: cannot pint, top empty/n");
                exit(EXIT_FAILURE);
        }
        else
        {
                printf("%d/n", top->n);
        }
}

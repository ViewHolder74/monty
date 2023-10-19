#include "monty.h"

int is_integer(char *str);

/**
 * push - Pushes an element onto the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");
    int value;
    stack_t *new_node;

    if (arg == NULL || !is_integer(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(arg);
    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack != NULL)
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
    }
    else
    {
        new_node->next = NULL;
    }

    *stack = new_node;
}

/**
 * pall - Prints all values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    while (*stack != NULL)
    {
        printf("%d\n", (*stack)->n);
        *stack = (*stack)->next;
    }
}

/**
 * is_integer - Checks if a string represents an integer.
 * @str: String to check.
 * Return: 1 if it's an integer, 0 otherwise.
 */
int is_integer(char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    if (*str == '-')
        str++;

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }

    return 1;
}


#include "monty.h"

int value;

/**
 * createNode - Creates a new node with the given value.
 * @n: The value of the node.
 * Return: A pointer to the new node.
 */
stack_t *createNode(int n)
{
    stack_t *new = NULL;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->n = n;
    new->next = NULL;
    new->prev = NULL;

    return (new);
}

/**
 * push - Pushes a new node with the given value onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number where the operation is performed.
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new = NULL;
    (void)line_number;

    new = createNode(value);

    new->next = *stack;
    if (*stack != NULL)
        (*stack)->prev = new;
    *stack = new;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = NULL;
    (void)line_number;

    tmp = *stack;

    while (tmp != NULL)
    {
        fprintf(stdout, "%d\n", tmp->n);
        tmp = tmp->next;
    }
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!*stack || !stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        clean_stack(stack);
        exit(EXIT_FAILURE);
    }
    else
        fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element from the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The current line number.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }
    else
    {
        temp = (*stack)->next;
        free(*stack);
        if (temp)
            temp->prev = NULL;
        *stack = temp;
    }
}

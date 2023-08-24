#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Double pointer to the head of the stack
 * @line_number: The current line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *top = *stack;
    int tmp = 0;

    if (top == NULL || top->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }
    else
    {
        tmp = top->n;
        top->n = top->next->n;
        top->next->n = tmp;
    }
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *top = *stack;
    int sum = 0;

    if (!top || !(top->next))
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }
    
    top = top->next;
    sum = (*stack)->n + top->n;
    pop(stack, line_number);
    top->n = sum;
}

/**
 * pchar - Prints the character value at the top of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (!*stack)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    
    if ((*stack)->n >= 0 && (*stack)->n <= 127)
        printf("%c\n", (*stack)->n);
    else
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }
}

/**
 * sub - Subtracts the top two elements of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: The line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *top = *stack;
    int diff = 0;

    if (!top || !(top->next))
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }
    
    top = top->next;
    diff = top->n - (*stack)->n;
    pop(stack, line_number);
    top->n = diff;
}

#include "monty.h"

/**
 * divide - Divides the second top element of the stack
 * by the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number where the operation occurs.
 */
void divide(stack_t **stack, unsigned int line_number)
{
    stack_t *val = NULL;
    int result = 0;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }

    val = (*stack)->next;
    result = val->n;
    result /= (*stack)->n;
    pop(stack, line_number);
    val->n = result;
}

/**
 * mul - Multiplies the second top element of the stack with
 * the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number where the operation occurs.
 */
void mul(stack_t **stack, unsigned int line_number)
{
    stack_t *val = NULL;
    int result = 0;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }

    val = (*stack)->next;
    result = val->n;
    result *= (*stack)->n;
    pop(stack, line_number);
    val->n = result;
}

/**
 * mod - Computes the remainder of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number where the operation occurs.
 */
void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *val = NULL;
    int result = 0;

    if (!*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        _free(*stack);
        exit(EXIT_FAILURE);
    }

    val = (*stack)->next;
    result = val->n;
    result %= (*stack)->n;
    pop(stack, line_number);
    val->n = result;
}

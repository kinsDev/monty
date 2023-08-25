#include "monty.h"

/**
 * _free - Recursively free the stack nodes and memory
 * @stack: Pointer to the top of the stack
 */
void _free(stack_t *stack)
{
    stack_t *list = NULL;

    list = stack;

    if (list != NULL)
    {
        _free(list->next);
        free(list);
    }
}

/**
 * clean_stack - Free all stack nodes and close files
 * @stack: Double pointer to the top of the stack
 */
void clean_stack(stack_t **stack)
{
    stack_t *tmp = *stack;

    while (tmp)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
    fclose(cmd.fd);
    free(cmd.line);
}

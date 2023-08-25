#include "monty.h"

/**
 * get_opc - Gets the appropriate opcode function
 * @stack: Pointer to the stack or queue
 * @arg: The opcode command
 * @val: The value associated with the command
 * @line_number: The line number in the script
 * Return: 0 on success, 1 if value is not a digit, -1 on error
 */

int get_opc(stack_t **stack, char *arg, char *val, int line_number)
{
    int i = 0;

    instruction_t op[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"nop", nop},
        {"swap", swap},
        {"add", add},
        {"sub", sub},
        {"div", divide},
        {"mul", mul},
        {"mod", mod},
        {"pchar", pchar},
        {NULL, NULL}
    };

    while (op[i].opcode)
    {
        if (!strcmp(arg, op[i].opcode))
        {
            if (!strcmp(arg, "push"))
            {
                if (_isdigit(val) == 1)
                    value = atoi(val);
                else
                    return (1); /* Return if the value is not a digit */
            }
            op[i].f(stack, (unsigned int)line_number);
            break;
        }
        i++;
    }
    if (!op[i].opcode)
        return (-1); /* Return if no matching opcode is found */

    return (0);
}

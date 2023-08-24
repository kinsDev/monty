#include "monty.h"

cmd_t cmd = {NULL, NULL};

/**
 * execute - Reads the file and executes the Monty byte code.
 * @argv: The argument vector containing the file name.
 */
void execute(char *argv)
{
    int c_line = 0, r = 0;
    size_t bufsize = 0;
    char *token = NULL, *val = NULL;
    stack_t *stack = NULL;

    cmd.fd = fopen(argv, "r");
    if (cmd.fd)
    {
        while (getline(&cmd.line, &bufsize, cmd.fd) != -1)
        {
            c_line++;
            token = strtok(cmd.line, " \n\t\r");
            if (token == NULL)
            {
                free(token);
                continue; /* Skip empty lines */
            }
            else if (*token == '#')
                continue; /* Skip comment lines */
            val = strtok(NULL, " \n\t\r");
            r = get_opc(&stack, token, val, c_line);
            if (r == 1) /* get_opc returns 1 when the value is not a digit */
                push_error(cmd.fd, cmd.line, stack, c_line); /* Print push error */
            else if (r == -1) /* get_opc returns -1 if it's not a recognized instruction */
                instr_error(cmd.fd, cmd.line, stack, token, c_line); /* Print instruction error */
        }
        free(cmd.line);
        _free(stack);
        fclose(cmd.fd);
    }
    else
    {
        open_error(argv); /* Print error for failed file open */
    }
}

#include "monty.h"

/**
 * usage_error - Prints an error message for incorrect usage
 * Return: Exits with FAILURE status
 */
void usage_error(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}

/**
 * open_error - Prints an error message when a file cannot be opened
 * @file: The name of the file
 * Return: Exits with FAILURE status
 */
void open_error(char *file)
{
    fprintf(stderr, "Error: Can't open file %s\n", file);
    exit(EXIT_FAILURE);
}

/**
 * push_error - Handles an error when push instruction format is invalid
 * @fd: File descriptor
 * @line: Buffer
 * @stack: Stack or queue
 * @line_number: Line number of the command
 */
void push_error(FILE *fd, char *line, stack_t *stack, int line_number)
{
    fprintf(stderr, "L%u: usage: push integer\n", line_number);
    fclose(fd);
    free(line);
    _free(stack);
    exit(EXIT_FAILURE);
}

/**
 * instr_error - Error handler for unknown instructions
 * @fd: File descriptor
 * @line: Buffer
 * @stack: Stack or queue
 * @instruction: Unknown instruction
 * @line_number: Line number of the command
 */
void instr_error(FILE *fd, char *line, stack_t *stack, char *instruction, int line_number)
{
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruction);
    fclose(fd);
    free(line);
    _free(stack);
    exit(EXIT_FAILURE);
}

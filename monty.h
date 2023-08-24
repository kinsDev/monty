#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/* External variables */
extern int info;

/**
 * struct cmd_s - Represents a command
 * @fd: File descriptor
 * @line: Line
 */
typedef struct cmd_s
{
    FILE *fd;
    char *line;
} cmd_t;

extern cmd_t cmd;
extern int value;

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value of the node
 * @prev: Points to the previous element in the stack (or queue)
 * @next: Points to the next element in the stack (or queue)
 *
 * Description: Node structure for a doubly linked list used in stack and queue.
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Represents an opcode and its function
 * @opcode: The opcode
 * @f: Function pointer to handle the opcode
 *
 * Description: Structure to define an opcode and its corresponding function.
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void execute(char *argv);
int get_opc(stack_t **stack, char *arg, char *val, int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
int check_push(char *token);
int get_value(char *token);
char get_token(char *op, char *token);
void _free(stack_t *stack);
void clean_stack(stack_t **stack);
void usage_error(void);
void open_error(char *file);
void push_error(FILE *fd, char *line, stack_t *stack, int line_number);
void instr_error(FILE *fd, char *line, stack_t *stack, char *val, int line_number);
int _isdigit(char *c);
stack_t *createNode(int n);

#endif

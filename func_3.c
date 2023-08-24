#include "monty.h"

/**
 * _isdigit - Checks if a string consists of digits
 * Return: 1 if all characters are digits, 0 otherwise
 * @c: String to be checked
 **/

int _isdigit(char *c)
{
    char *tmp = c;

    if (c == NULL)
        return (0);
    
    if (*tmp == '-')
        tmp++;

    for (; *tmp != '\0'; tmp++)
    {
        if (*tmp < '0' || *tmp > '9')
        {
            return (0);
        }
    }
    
    return (1);
}

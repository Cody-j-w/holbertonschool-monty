#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"

void (*get_command(char *op))(stack_t **stack, unsigned int line_number)
{
    int i = 0;
    int comparison;
    instruction_t list[] = {
        {"push", push_m},
        {"pall", pall_m},
        {NULL, NULL}
    };

    while (list[i] != NULL)
    {
        comparison = strcmp(op, list[i].opcode);
        if (comparison == 0)
            return (list[i].f);
        i++;
    }
    return (NULL);
}
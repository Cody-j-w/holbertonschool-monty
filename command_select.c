#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"

/**
 * get_command - fetch the command passed, if it is valid
 * @op: the command to be returned
 * @count: the current line number of the file, for error handling
 *
 * Return: the requested command, if valid
*/
void (*get_command(char *op))(stack_t **stack, unsigned int data)
{
	int i = 0;
	int comparison;
	instruction_t list[] = {
		{"push", push_m},
		{NULL, NULL}
	};

	while (i < 1)
	{
		comparison = strcmp(op, list[i].opcode);
		if (comparison == 0)
			return (list[i].f);
		i++;
	}
	null_command(op);
	exit(EXIT_FAILURE);
}

void (*get_print(char *op))(stack_t **stack, unsigned int data)
{
	int i = 0;
	int comparison;
	instruction_t p_list[] = {
		{"pall", pall_m},
		{"pint", pint_m},
		{NULL, NULL}
	};

	while (i < 2)
	{
		comparison = strcmp(op, p_list[i].opcode);
		if (comparison == 0)
			return (p_list[i].f);
		i++;
	}
	return (0);
}
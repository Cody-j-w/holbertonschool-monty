#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * null_file - error message for missing/inaccessible file
 * @str: the file name
*/
void null_file(char *str)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	exit(EXIT_FAILURE);
}

/**
 * count_error - error message for incorrect number of arguments
*/
void count_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * null_command - error message for invalid command
 * @command: the string passed as a command
 * @count: the line number the command appears on
*/
void null_command(char *command)
{
	extern int line_count;
	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, command);
	exit(EXIT_FAILURE);
}

/**
 * null_int - error message for invalid data
 * @count: the line number the error appears on
*/
void null_int(void)
{
	extern int line_count;
	fprintf(stderr, "L%d: usage: push integer\n", line_count);
	exit(EXIT_FAILURE);
}

void pint_err(void)
{
	extern int line_count;
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_count);
	exit(EXIT_FAILURE);
}

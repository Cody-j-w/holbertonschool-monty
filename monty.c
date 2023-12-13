#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"



int main(int argc, char *argv[])
{
    size_t buffsize = 512;
    unsigned int data = 0, count = 0;
    char *buffer = malloc(buffsize * sizeof(char)), *cmd;
    stack_t *stack = NULL;
    FILE *file = fopen(argv[1], "r");
    void (*op_func)(stack_t **, unsigned int);

    if (argc != 2)
        count_error();
    if (file == NULL)
        null_file(argv[1]);

    while (getline(&buffer, &buffsize, file) != -1)
    {
        count++;
        if ((cmd = cmdstr(strtok(buffer, " \n")))[0] == '\0')
            continue;
        data = cmdval(strtok(0, " \n"), count);
        op_func = get_command(cmd);
        if (op_func == NULL)
            null_command(cmd, count);
        else
            op_func(&stack, data);
    }
    free_stack(stack);
    free(buffer);
    fclose(file);
    return(EXIT_SUCCESS);
}

void free_stack(stack_t *head)
{
    	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

char *cmdstr(char *str)
{
    if (str == NULL)
        count_error();
    return (str);
}

int cmdval(char *str, int count)
{
    int i = 0;
    int valcheck = strcmp(str, "");
    if (str == NULL || valcheck == 0)
        null_int(count);
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            null_int(count);
        i++;
    }
    return (atoi(str));
}

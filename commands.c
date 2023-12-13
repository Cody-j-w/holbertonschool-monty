#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

void push_m(stack_t **head, unsigned int data)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = data;
	if (*head == NULL)
	{
		free(new_node);
		*head = malloc(sizeof(stack_t));
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*head)->n = data;
	}
	else
	{
		new_node->next = *head;
		new_node->prev = NULL;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

void pall_m(stack_t **head)
{
	stack_t *temp = *head;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

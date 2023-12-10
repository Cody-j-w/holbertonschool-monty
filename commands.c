void push_m(stack_t **head, unsigned int data)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = data;
	if (*head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		new_node->prev = NULL;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

void pall_m(stack_t **head, unsigned int data __attribute__((unused)))
{
	stack_t *temp = NULL;

	if (*head == NULL)
		return (0);
	temp = *head;
	if ((*head)->prev != NULL)
	{
		while (temp->prev != NULL)
		{
			temp = temp->prev;
		}
	}
	while (temp != NULL)
	{
		count++;
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

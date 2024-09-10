#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int p;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}
	current = *head;

	if (0 == index)
	{
		*head = current->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(current);
		return	(1);
	}

	p = 0;
	while (p < index && current != NULL)
	{
		*head = (*head)->next;
		p++;
	}
	if (current == NULL)
	{
		return (-1);
	}
	if (current->next != NULL)
	{
		current->next->prev = current->prev;
	}
	if (current->prev != NULL)
	{
		current->prev->next = current->next;
	}
	free(current);
	return (1);
}
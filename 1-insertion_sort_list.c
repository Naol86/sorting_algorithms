#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || (*list)->next == NULL)
	{
		print_list(*list);
		return;
	}
	current = (*list)->next;
	while (current)
	{
		if (current->prev->n > current->n)
		{
			temp = current;
			while (temp->prev != NULL && temp->n < temp->prev->n)
			{
				if (temp->next != NULL)
				{
					temp->next->prev = temp->prev;
					temp->prev->next = temp->next;
				}
				else
					temp->prev->next = NULL;
				current = temp->prev->next;
				temp->next = temp->prev;
				if (temp->prev->prev == NULL)
				{
					temp->prev = NULL;
					(*list) = temp;
				}
				else
				{
					temp->prev = temp->prev->prev;
					temp->prev->next = temp;
				}
				temp->next->prev = temp;
			}
		}
		else
			current = current->next;
	}
	print_list(*list);
}
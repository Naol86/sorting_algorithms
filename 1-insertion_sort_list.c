#include "sort.h"

/**
 * swap_node - Swaps two nodes in a doubly linked list.
 * @h: A double pointer to the head of the doubly linked list.
 * @a: A pointer to the first node to be swapped.
 * @b: A pointer to the second node to be swapped.
 */
void swap_node(listint_t **h, listint_t *a, listint_t *b)
{
	if (a->prev == NULL)
	{
		b->prev = NULL;
		*h = b;
	}
	else
	{
		b->prev = a->prev;
		a->prev->next = b;
	}
	if (b->next == NULL)
		a->next = NULL;
	else
	{
		a->next = b->next;
		b->next->prev = a;
	}
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - sorting double linked list
 * @list: list head
 */

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
				swap_node(list, temp->prev, temp);
				print_list(*list);
			}
		}
		current = current->next;
	}
}

#include "sort.h"
/**
 * cocktail_sort_list - sorts doubly linked list using cocktail sort
 * @list: doubly linked list
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *holder, *lasth;
	int is_sorted = 1;

	holder = (*list);
	do {
		is_sorted = 0;
		while (holder)
		{
			if (holder != NULL && holder->next != NULL && holder->n > holder->next->n)
			{
				swap_node(list, holder, holder->next);
				is_sorted = 1;
				print_list(*list);
			}
			else
			{
				lasth = holder;
				holder = holder->next;
			}
		}
		holder = lasth->prev;
		while (holder)
		{
			if (holder != NULL && holder->prev != NULL && holder->n < holder->prev->n)
			{
				swap_node(list, holder->prev, holder);
				is_sorted = 1;
				print_list(*list);
			}
			else
			{
				lasth = holder;
				holder = holder->prev;
			}
		}
		holder = lasth->next;
	} while (is_sorted);
}

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

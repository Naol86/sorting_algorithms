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
	while(current){
		if(current->prev->n > current->n){
			temp = current;
			printf("this count %d\n",current->n);
			while(temp && temp->n < temp->prev->n){
				printf("this is preve ");
				print_list(*list);
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				temp->next = temp->prev;
				temp->prev = temp->prev->prev;
				temp->prev->next = temp;
				temp->next->prev = temp;
				printf("this is after ");
				print_list(*list);
			}
		}
		current = current->next;
	}
}
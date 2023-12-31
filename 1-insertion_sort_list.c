#include "sort.h"

/**
 * insertion_sort_list - sort linked list using insertion method.
 * @list: input linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *holder;
	listint_t *node_holder;
	int flag;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = (*list)->next;
	while (curr != NULL)
	{
		holder = curr;
		while (holder->prev != NULL)
		{
			flag = 0;
			if (holder->n < holder->prev->n)
			{
				if (holder->prev->prev != NULL)
					holder->prev->prev->next = holder;
				holder->prev->next = holder->next;
				node_holder = holder->prev->prev;
				holder->prev->prev = holder;
				if (holder->next != NULL)
					holder->next->prev = holder->prev;
				holder->next = holder->prev;
				holder->prev = node_holder;
				flag = 1;
				if (holder->prev == NULL)
					*list = holder;
				print_list(*list);
			}
			if (flag == 0)
				holder = holder->prev;
		}
		curr = curr->next;
	}
}

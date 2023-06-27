#include "sort.h"

/**
 * swapp - swapps a linked list
 * @holder: curr location of linked list
 * @list: double pointer to list
 * Return: return the new pointer
 */
listint_t *swapp(listint_t *holder, listint_t **list)
{
	listint_t *node_holder;

	if (holder->prev->prev != NULL)
		holder->prev->prev->next = holder;
	holder->prev->next = holder->next;
	node_holder = holder->prev->prev;
	holder->prev->prev = holder;
	if (holder->next != NULL)
		holder->next->prev = holder->prev;
	holder->next = holder->prev;
	holder->prev = node_holder;
	if (holder->prev == NULL)
		*list = holder;
	return (holder);
}

/**
 * cocktail_sort_list - sort linked list using cocktail sort method
 * @list: input linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;

	int flag = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list);

	while (flag != 0)
	{
		flag = 0;
		while (curr->next != NULL)
		{
			if (curr->n > curr->next->n)
			{
				curr = swapp(curr->next, list);
				print_list(*list);
				flag = 1;
			}
			curr = curr->next;
		}
		curr = curr->prev;

		while (curr->prev != NULL)
		{
			if (curr->prev->n > curr->n)
			{
				curr = swapp(curr, list);
				print_list(*list);
				flag = 1;
			}
			else if (curr->prev != NULL)
				curr = curr->prev;
		}

		curr = curr->next;
	}
}

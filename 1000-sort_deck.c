#include "deck.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(deck_node_t *node1, deck_node_t *node2)
{
    	deck_node_t *temp_prev;
    deck_node_t *temp_next;
	
	if (node1 == node2)
        return;

    if (node1->prev)
        node1->prev->next = node2;
    if (node2->prev)
        node2->prev->next = node1;

    if (node1->next)
        node1->next->prev = node2;
    if (node2->next)
        node2->next->prev = node1;

    temp_prev = node1->prev;
    temp_next = node1->next;

    node1->prev = node2->prev;
    node1->next = node2->next;

    node2->prev = temp_prev;
    node2->next = temp_next;
}

/**
 * partition - Partitions the deck using the last card as pivot
 * @head: Pointer to the head node of the deck
 * @tail: Pointer to the tail node of the deck
 * @pivot: Pointer to the pivot node
 * Return: Pointer to the new pivot node
 */
deck_node_t *partition(deck_node_t *head, deck_node_t *tail, deck_node_t *pivot)
{
    deck_node_t *i = head->prev;
	deck_node_t *j;

    for (j = head; j != tail; j = j->next)
    {
        if (strcmp(j->card->value, pivot->card->value) < 0 ||
            (strcmp(j->card->value, pivot->card->value) == 0 &&
             j->card->kind < pivot->card->kind))
        {
            i = (i == NULL) ? head : i->next;
            swap_nodes(i, j);
        }
    }

    i = (i == NULL) ? head : i->next;
    swap_nodes(i, tail);
    return i;
}

/**
 * quick_sort - Recursive function to perform quick sort
 * @head: Pointer to the head node of the deck
 * @tail: Pointer to the tail node of the deck
 */
void quick_sort(deck_node_t *head, deck_node_t *tail)
{
    if (tail != NULL && head != tail && head != tail->next)
    {
        deck_node_t *pivot = tail;
        deck_node_t *partition_node = partition(head, tail, pivot);

        quick_sort(head, partition_node->prev);
        quick_sort(partition_node->next, tail);
    }
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head node of the deck
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *tail;
	tail = *deck;

	if (deck == NULL || *deck == NULL)
		return;

	while (tail->next != NULL)
		tail = tail->next;

	quick_sort(*deck, tail);
}

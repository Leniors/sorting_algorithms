#include "sort.h"

/**
 * @list: pointer to linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (*list == NULL || list == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		prev = current->prev;
		while (prev && prev->n > temp->n)
		{
			if (temp->next)
				temp->next->prev = prev;

			prev->next = temp->next;
			temp->prev = prev->prev;
			prev->prev = temp;
			temp->next = prev;

			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;

			print_list(*list);
			prev = temp->prev;
		}
		current = current->next;
	}
}

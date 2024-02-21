#include "sort.h"
#include <stdlib.h>
void insertion_sort_list(listint_t **list);

/**
* insertion_sort_list - func to do insertion
* @list: arg
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j, *temp;
	int key;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp = malloc(sizeof(listint_t));

	/* check if malloc encounters error */
	if (temp != NULL)
	{
		temp = *list;
		temp = temp->next;

		for (i = temp; i != NULL; i = i->next)
		{
			key = i->n;
			j = i->prev;

			while ((j != NULL) && (j->n > key))
			{
				/* swap nodes */
				i->prev = j->prev;
				j->prev = i;
				j->next = i->next;

				if (i->next != NULL)
				{
					i->next->prev = j;
				}

				i->next = j;

				if (i->prev == NULL)
				{
					*list = i;
				}
				else
				{
					i->prev->next = i;
				}

				j = i->prev;
				print_list(*list);
			}
		}
	}
}

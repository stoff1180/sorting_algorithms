#include "sort.h"

/**
 * swap - swaps two nodes in a double linked list
 * @a: address of first node
 * @b: address of second node
 * Return: nothing
 */
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - insertion sorts a double linked list
 * @list: address of pointer to head node
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *p, *ptr;

	if (!list || !*list || !(*list)->next)
		return;
	p = (*list)->next;
	while (p)
	{
		ptr = p;
		p = p->next;
		while (ptr && ptr->prev)
		{
			if (ptr->prev->n > ptr->n)
			{
				swap(ptr->prev, ptr);
				if (!ptr->prev)
					*list = ptr;
				print_list((const listint_t *)*list);
			}
			else
				ptr = ptr->prev;
		}
	}
}

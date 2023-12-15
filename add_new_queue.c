#include "monty.h"

/**
 * add_new_queue - Adds a new node with the specified integer value to the end
 *                of the doubly linked list (queue).
 * @head: Double pointer to the head of the doubly linked list.
 * @num: Integer value to be added to the new node.
 */

void add_new_queue(stack_t **head, int num)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		printf("Stack overflow\n");

	new_node->n = num;
	new_node->next = NULL;

	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}

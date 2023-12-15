#include "monty.h"

/**
 * add_new_node - Adds a new node to the beginning of the stack.
 * @head: Double pointer to the top of the stack.
 * @num: Value to be stored in the new node.
 *
 * Description: This function creates a new node with the given value (@n) and
 * adds it to the beginning of the stack. If memory allocation for the new node
 * fails, the function prints an error message and exits the program. The new
 * node becomes the new top of the stack, and any existing nodes are
 * appropriatelyadjusted to maintain the doubly linked list structure.
 */
void add_new_node(stack_t **head, int num)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (temp)
		temp->prev = new_node;

	new_node->n = num;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

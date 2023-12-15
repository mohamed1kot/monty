#include "monty.h"

/**
 * free_stack - Frees the memory allocated for
 * all nodes in a doubly linked list.
 * @head: Pointer to the top of the stack.
 *
 * Description: This function iterates through the doubly linked list starting
 * from the top and frees the memory allocated for each node.
 * It uses a temporary
 * pointer `tmp` to keep track of the next node before freeing the current one.
 * After freeing all nodes, the list is effectively empty, and the head pointer
 * is set to NULL.
 */

void free_stack(stack_t *head)
{
	stack_t *tmp;

	tmp = head;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * _stack - Sets the global variable bus.lifi to 0.
 * @head: Unused parameter (not used in this function).
 * @count: Unused parameter (not used in this function).
 *
 * Description: This function is intended to be used as part of an opcode
 * handling mechanism. It sets the global variable bus.lifi to 0, indicating
 * that subsequent push operations should add elements to the top of the stack
 * (LIFO) rather than the end (FIFO/queue).
 */

void _stack(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;

	bus.lifi = 0;
}

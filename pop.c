#include "monty.h"

/**
 * _pop - Removes the top element from the stack.
 * @head: Double pointer to the top of the stack.
 * @count: Line number of the opcode in the input file.
 *
 * Description: This function removes the top element from the stack.
 * If the stack is empty, it prints an error message and exits the program
 * with EXIT_FAILURE. The memory of the removed element is freed, and the top
 * of the stack is updated to point to the next element.
 */

void _pop(stack_t **head, unsigned int count)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	*head = h->next;
	free(h);
}

#include "monty.h"

/**
 * _swap - Swaps the top two elements of the stack.
 * @head: Double pointer to the top of the stack.
 * @count: Line number of the opcode in the input file.
 *
 * Description: This function swaps the values of the top two elements of
 * the stack. If the stack has fewer than two elements, it prints an error
 * message and exits the program with EXIT_FAILURE. The top two elements are
 * swapped, and the stack remains unchanged in size. The function uses a
 * temporary variable to perform the swap operation.
 */

void _swap(stack_t **head, unsigned int count)
{
	stack_t *h;
	int l = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	tmp = h->n;
	h->n = h->next->n;
	h->next->n = tmp;
}

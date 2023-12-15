#include "monty.h"

/**
 * _pall - Prints all the values on the stack.
 * @head: Double pointer to the top of the stack.
 * @count: Line number of the opcode in the input file.
 *
 * Description: This function prints all
 * the integer values stored on the stack.
 * If the stack is empty, it does nothing. Otherwise,
 * it traverses the stack and
 * prints each value followed by a new line.
 * The line number of the opcode is used
 * to meet the function signature but is not used in the implementation.
 */

void _pall(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	if (h == NULL)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

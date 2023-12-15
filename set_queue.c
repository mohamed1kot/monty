#include "monty.h"

/**
 * _queue - Sets the global variable bus.lifi to 1.
 * @head: Unused parameter (not used in this function).
 * @count: Unused parameter (not used in this function).
 *
 * Description: This function is intended to be used as a part of an opcode
 * handling mechanism. It sets the global variable bus.lifi to 1, indicating
 * that subsequent push operations should add elements to the end of the stack
 * (FIFO/queue) rather than the top (LIFO).
 */

void _queue(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;

	bus.lifi = 1;
}

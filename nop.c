#include "monty.h"

/**
 * _nop - Does nothing.
 * @head: Double pointer to the top of the stack.
 * @count: Line number of the opcode in the input file.
 *
 * Description: This function does nothing and is used as a placeholder
 * for the "nop" opcode. It takes the double pointer to the top of the stack
 * and the line number of the opcode as arguments but does not perform any
 * operations. It is mainly used for alignment or as a placeholder in the
 * instruction set.
 */

void _nop(stack_t **head, unsigned int count)
{
	(void) count;
	(void) head;
}

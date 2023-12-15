#include "monty.h"

/**
 * _pint - Prints the value at the top of the stack.
 * @head: Double pointer to the top of the stack.
 * @count: Line number of the opcode in the input file.
 *
 * Description: This function prints the integer value stored at the top
 * of the stack. If the stack is empty, it prints an error message and exits
 * the program with EXIT_FAILURE. Otherwise, it prints the value followed by
 * a new line.
 */

void _pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

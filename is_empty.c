#include "monty.h"

/**
 * _pchar - Prints the ASCII character of the top element of the stack.
 * @head: Double pointer to the top of the stack.
 * @count: Line number of the opcode in the input file.
 *
 * Description: This function checks if the stack is empty. If so, it prints
 * an error message and exits the program with EXIT_FAILURE.
 * If the stack is not
 * empty, it checks if the top element is within
 * the valid ASCII range (0 to 127).
 * If not, it prints an error message and exits the program with EXIT_FAILURE.
 * Otherwise, it prints the corresponding ASCII
 * character followed by a new line.
 * The memory of the removed element is not freed in this function.
 */

void _pchar(stack_t **head, unsigned int count)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

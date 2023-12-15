#include "monty.h"

/**
 * _mul - Multiplies the top two elements of the stack.
 * @head: Double pointer to the top of the stack.
 * @count: Line number of the opcode in the input file.
 *
 * Description: This function checks if the stack has at least two elements.
 * If not, it prints an error message and exits the program with EXIT_FAILURE.
 * If the stack has two or more elements, it multiplies the values of the top
 * two elements, updates the second element with the result,
 * and removes the top
 * element from the stack. The memory of the removed element is freed.
 */

void _mul(stack_t **head, unsigned int count)
{
	stack_t *H;
	int length = 0, temp;

	H = *head;
	while (H)
	{
		H = H->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	H = *head;
	temp = H->next->n * H->n;
	H->next->n = temp;
	*head = H->next;
	free(H);
}

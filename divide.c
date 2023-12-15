#include "monty.h"

/**
 * _div - Divides the second element by the top element of the stack.
 * @head: Double pointer to the top of the stack.
 * @count: Line number of the opcode in the input file.
 *
 * Description: This function checks if the stack has at least two elements.
 * If not, it prints an error message and exits the program with EXIT_FAILURE.
 * If the stack has two or more elements, it divides the value of the second
 * element by the top element, updates the second element with the result, and
 * removes the top element from the stack. If the top element is 0, it prints
 * an error message for division by zero and exits the program with
 * EXIT_FAILURE.
 * The memory of the removed element is freed.
 */

void _div(stack_t **head, unsigned int count)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	H = *head;
	if (H->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = H->next->n / H->n;
	H->next->n = temp;
	*head = H->next;
	free(H);
}

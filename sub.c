#include "monty.h"


/**
 * _sub - Subtracts the top element from the second element of the stack.
 * @head: Double pointer to the top of the stack.
 * @count: Line number of the opcode in the input file.
 *
 * Description: This function checks if the stack has at least two elements.
 * If not, it prints an error message and exits the program with EXIT_FAILURE.
 * If the stack has two or more elements, it subtracts the value of the top
 * element from the second element, updates the second element with the result,
 * and removes the top element from the stack.
 * The memory of the removed element
 * is freed.
 */

void _sub(stack_t **head, unsigned int count)
{
	stack_t *tmp;
	int sub, N;

	tmp = *head;
	for (N = 0; tmp != NULL; N++)
		tmp = tmp->next;

	if (N < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sub = tmp->next->n - tmp->n;
	tmp->next->n = sub;
	*head = tmp->next;
	free(tmp);
}

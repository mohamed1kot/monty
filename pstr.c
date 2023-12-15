#include "monty.h"

/**
 * _pstr - Prints the string of ASCII characters on the stack.
 * @head: Double pointer to the top of the stack.
 * @count: Line number of the opcode in the input file (unused).
 *
 * Description: This function iterates through the elements on the stack
 * starting from the top. It prints each ASCII character represented by the
 * element's value until it encounters a non-printable character (outside the
 * range of 0 to 127) or a zero value. The printing stops at the first
 * non-printable character or zero value. The newline character is printed
 * after the string. The memory of the elements is not freed in this function.
 */

void _pstr(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}

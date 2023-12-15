#include "monty.h"

/**
 * _push - Adds a new node with the specified integer value to the stack.
 * @head: Double pointer to the top of the stack.
 * @count: Line number of the opcode in the input file.
 *
 * Description: This function first checks
 * if the argument for push is provided.
 * If not, it prints an error message and exits the program with EXIT_FAILURE.
 * If an argument is provided, it checks if it is a valid integer. If not, it
 * prints an error message and exits the program with EXIT_FAILURE. If the
 * argument is a valid integer, it converts it to an integer using the atoi
 * function and adds a new node with that value to the stack. The type of
 * insertion (LIFO or FIFO) is determined by the value of the global variable
 * bus.lifi. If bus.lifi is 0, the element is added to the top of the stack
 * (LIFO). If bus.lifi is 1, the element is added to the end of the stack
 * (FIFO/queue). The function uses the add_new_node or add_new_queue function
 * accordingly.
 */

void _push(stack_t **head, unsigned int count)
{
	int i, m = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			m++;
		for (; bus.arg[m] != '\0'; m++)
		{
			if (bus.arg[m] > 57 || bus.arg[m] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", count);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.lifi == 0)
		add_new_node(head, i);
	else
		add_new_queue(head, i);
}

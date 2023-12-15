#include "monty.h"

/**
 * _rotl - Rotates the doubly linked list (stack) to the left.
 * @head: Double pointer to the top of the stack.
 * @count: Unused parameter (not used in this function).
 *
 * Description: This function rotates the doubly linked list to the left,
 * moving the top element to the bottom. If the stack is empty or has only
 * one element, the rotation has no effect. The unused parameter `count` is
 * present to maintain consistency with other opcode handling functions.
 */

void _rotl(stack_t **head,  __attribute__((unused)) unsigned int count)
{
	stack_t *tmp = *head, *A;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	A = (*head)->next;
	A->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = A;
}

/**
 * _rotr - Rotates the doubly linked list (stack) to the right.
 * @head: Double pointer to the top of the stack.
 * @count: Unused parameter (not used in this function).
 *
 * Description: This function rotates the doubly linked list to the right,
 * moving the bottom element to the top. If the stack is empty or has only
 * one element, the rotation has no effect. The unused parameter `count` is
 * present to maintain consistency with other opcode handling functions.
 */

void _rotr(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

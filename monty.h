#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct BUS_s - Configuration structure for a BUS system
 * @arg: A string representing an argument related to the BUS
 * @file: A pointer to a FILE structure associated with the BUS
 * @content: A string representing content or data associated with the BUS
 * @lifi: An integer representing a flag or indicator for the BUS
 *
 * Description: This structure defines a configuration for a BUS system,
 * where a BUS has various attributes such as an argument (@arg), a file
 * pointer (@file), content or data (@content), and a lifi indicator (@lifi).
 * It is used to manage and store information related to the BUS in a program.
*/

typedef struct BUS_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  BUS_t;
extern BUS_t bus;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);

char  *rem_line(char *content);
void free_stack(stack_t *head);

int Execute(char *content, stack_t **head, unsigned int count, FILE *file);

void _push(stack_t **head, unsigned int number);
void _pall(stack_t **head, unsigned int number);
void _pint(stack_t **head, unsigned int number);
void _pop(stack_t **head, unsigned int count);
void _swap(stack_t **head, unsigned int count);
void _nop(stack_t **head, unsigned int count);

void _add(stack_t **head, unsigned int count);
void _sub(stack_t **head, unsigned int count);
void _div(stack_t **head, unsigned int count);
void _mul(stack_t **head, unsigned int count);
void _mod(stack_t **head, unsigned int count);

void _pchar(stack_t **head, unsigned int count);
void _pstr(stack_t **head, unsigned int count);

void _rotl(stack_t **head, unsigned int count);
void _rotr(stack_t **head, __attribute__((unused)) unsigned int count);

void add_new_node(stack_t **head, int n);
void add_new_queue(stack_t **head, int n);
void _queue(stack_t **head, unsigned int count);
void _stack(stack_t **head, unsigned int count);
int _strcmp(char *str1, char *str2);
char **_strtok(char *str, char *C);
#endif

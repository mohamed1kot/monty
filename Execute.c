#include "monty.h"

/**
 * Execute - Executes Monty bytecode instructions.
 * @content: String containing a single line of Monty bytecode.
 * @STACK: Double pointer to the top of the STACK.
 * @count: Line number of the current instruction in the input F.
 * @F: Pointer to the input F.
 *
 * Return: 0 on successful execution, 1 on unknown instruction error.
 *
 * Description: This function takes a line of Monty bytecode and executes the
 * corresponding instruction based on the opcode.
 * It uses an array of structures
 * (opst) containing opcodes and their associated functions.
 * The function tokenizes
 * the input line to extract the opcode and argument (if any),
 * and then compares
 * the opcode with the opst array. If a match is found,
 * the corresponding function
 * is called to execute the instruction. If the opcode is not recognized,
 * it prints
 * an error message and exits the program with EXIT_FAILURE.
 */

int Execute(char *content, stack_t **STACK, unsigned int count, FILE *F)
{
	instruction_t opst[] = {
				{"push", _push}, {"pall", _pall}, {"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"add", _add},
				{"nop", _nop},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"pchar", _pchar},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{"queue", _queue},
				{"STACK", _stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (_strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(STACK, count);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(F);
		free(content);
		free_stack(*STACK);
		exit(EXIT_FAILURE); }
	return (1);
}

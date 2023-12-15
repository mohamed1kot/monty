#include "monty.h"

BUS_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: EXIT_SUCCESS on successful execution, EXIT_FAILURE on failure.
 *
 * Description: This function serves as the entry point for the Monty bytecode
 * interpreter. It takes the name of a Monty bytecode file as a command-line
 * argument and reads the file line by line.
 * For each line, it calls the Execute
 * function to execute the corresponding Monty instruction.
 * The function handles
 * file opening errors, and if the file can't be opened,
 * it prints an error message
 * and exits the program with EXIT_FAILURE.
 * The memory allocated for each line of
 * the file is freed after processing.
 * At the end of execution, the function frees
 * the memory used by the stack and closes the file.
 */

int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;

		if (read_line > 0)
			Execute(content, &stack, counter, file);

		free(content);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}

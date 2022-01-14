#include "monty.h"
/**
 * main - Main function.
 * @argc: The argument count.
 * @argv: The argument vector.
 * Description: This is the main function of the Monty project.
 * Return: The success or error.
 */
int main(int argc, char *argv[])
{
	FILE *monty_file;

	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop},   {"swap", swap}, {"add", add},
		{"sub", sub},   {"mul", mul},   {"mod", mod},
		{"pchar", pchar}, {"nop", nop}, {"pstr", pstr},
		{"rotl", rotl},   {"rotr", rotr}, {"stack", stack},
		{"queue", queue}, {"null", NULL},
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	parse_execute(monty_file, instructions);
	fclose(monty_file);
	return (0);
}

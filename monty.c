#include "monty.h"

/**
 * parse_execute - This function parse lines from a text.m
 * @monty_file: File with monty steps to execute.
 * @instructions: All the list-displays from functions.
 * Return: .
 */

void parse_execute(FILE *monty_file, instruction_t instructions[])
{
	unsigned int ln_cont = 1;
	stack_t *stack = NULL;
	char *token = NULL;
	char line[100];
	int i, enter, stack_case = 0;

	while (fgets(line, sizeof(line), monty_file))
	{
		enter = 0;
		token = strtok(line, LIMITERS);

		if (token)
		{
			for (i = 0; i < 18; i++)
			{
				if (strcmp(token, instructions[i].opcode) == 0)
				{
					if (i == 0)
					{
						token = strtok(NULL, LIMITERS);
						tk_error(stack, ln_cont, monty_file, token);
						is_number(stack, ln_cont, token, monty_file);
						n = atoi(token);
					}
					Manage_1(&stack, ln_cont, monty_file, i);
					if (stack_case == 1 && i == 0)
						i = 17;
					if (i == 16)
						stack_case = 1;
					else if (i == 15)
						stack_case = 0;
					instructions[i].f(&stack, ln_cont);
					enter = 1;
				}
			}
			comt(stack, ln_cont, token, monty_file, enter);
		}
		ln_cont++;
	}
	frees(stack);
}


/**
 * frees - This function frees memory
 * @stack: stack.
 * Return: .
 */

void frees(stack_t *stack)
{
	stack_t *delete = NULL;

	while (stack)
	{
		delete = stack;
		stack = stack->next;
		free(delete);
	}
}
/**
 * is_number - Checks if a string is a number.
 * @token: String to compare.
 * @stack: Stack.
 * @lnumber: Line number.
 * @mfile: Monty file.
 * Return: .
 */

void is_number(stack_t *stack, unsigned int lnumber, char *token, FILE *mfile)
{
	int i = 0;

	if (token[0] == '-' && token[1])
		i++;
	while (token[i])
	{
		if (token[i] < 48 || token[i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", lnumber);
			frees(stack);
			fclose(mfile);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}


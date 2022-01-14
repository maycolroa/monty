#include "monty.h"

/**
 * Manage_1 - Manage errors.
 * @stack: Stack.
 * @line_number: Line number.
 * @m_file: Monty file.
 * @i: Instruction.
 * Return: .
 */

void Manage_1(stack_t **stack, unsigned int line_number, FILE *m_file, int i)
{
	int execute = 0;

	if (i == 2)
	{
		if (!*stack)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
			execute = 1;
		}
	}

	else if	 (i == 3)
	{
		if (!*stack)
		{
			fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
			execute = 1;
		}
	}

	if (execute == 0)
		execute = Manage_2(stack, line_number, i);

	if (execute == 0)
		execute = Manage_3(stack, line_number, i);

	if (execute == 0)
		execute = Manage_4(stack, line_number, i);

	if (execute == 1)
	{
		frees(*stack);
		fclose(m_file);
		exit(EXIT_FAILURE);
	}
}

/**
 * Manage_2 - Manage errors.
 * @stack: Stack.
 * @line_number: Line number.
 * @i: Instruction.
 * Return: (1) (0).
 */

int Manage_2(stack_t **stack, unsigned int line_number, int i)
{

	if (i == 8)
	{
		if (!*stack || !(*stack)->next)
		{
			fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
			return (1);
		}
	}

	else if (i == 4)
	{
		if (!*stack || !(*stack)->next)
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
			return (1);
		}
	}

	else if (i == 5)
	{
		if (!*stack || !(*stack)->next)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
			return (1);
		}
	}

	return (0);
}

/**
 * Manage_3 - Manage errors
 * @stack: Stack.
 * @line_number: Line number.
 * @i: Instruction.
 * Return: (1) (0).
 */

int Manage_3(stack_t **stack, unsigned int line_number, int i)
{
	if (i == 6)
	{
		if (!*stack || !(*stack)->next)
		{
			fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
			return (1);
		}
	}

	else if (i == 7)
	{
		if (!*stack || !(*stack)->next)
		{
			fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
			return (1);
		}

		else if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			return (1);
		}
	}
	return (0);
}

/**
 * Manage_4 - Manage errors.
 * @stack: Stack.
 * @line_number: Line number.
 * @i: Instruction.
 * Return: (1) (0).
 */

int Manage_4(stack_t **stack, unsigned int line_number, int i)
{
	if (i == 9)
	{
		if (!*stack || !(*stack)->next)
		{
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
			return (1);
		}

		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			return (1);
		}
	}

	else if (i == 10)
	{
		if (!*stack)
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			return (1);
		}

		if ((*stack)->n < 32 || (*stack)->n > 126)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			return (1);
		}
	}
	return (0);
}

#include "monty.h"

/**
 * pstr -  prints the string
 * @stack: Double pointer
 * @ln_cont: line number.
 * Return: .
 */

void pstr(stack_t **stack, unsigned int ln_cont)
{
	stack_t *list = *stack;
	(void) ln_cont;

	while (list)
	{
		if (list->n >= 32 && list->n <= 126)
			printf("%c", list->n);

		else
			break;

		list = list->next;
	}

	printf("\n");
}

/**
 * comment - Check if token is a comment or not.
 *
 * @head: Stack.
 * @ln: Line number.
 * @tokenk: Token.
 * @file: Monty file.
 * @enter: Execute case.
 *
 * Return: Nothing.
 */

void comment(stack_t *head, unsigned int ln, char *token, FILE *file, int enter)
{
	if (enter == 0 && token[0] != '#')
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, token);
		frees(head);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * stack - Doesn’t do anything.
 * @stack: Stack.
 * @line_number: Line number.
 * Return: .
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * queue - Doesn’t do anything.
 * @stack: Stack.
 * @line_number: Line number.
 * Return: .
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * token_error - Checks if token value is NULL.
 *
 * @stack: Stack.
 * @number: Line number.
 * @arc_monty: Monty arc_monty.
 * @tok: Number.
 *
 * Return: Nothing.
 */

void token_error(stack_t *stack, unsigned int number, FILE *arc_monty, char *tok)
{
	if (!tok)
	{
		fprintf(stderr, "L%d: usage: push integer\n", number);
		frees(stack);
		fclose(arc_monty);
		exit(EXIT_FAILURE);
	}
}

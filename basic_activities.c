#include "monty.h"

/**
 * push - pushes an element
 * @stack: Double pointer
 * @ln_cont: line number.
 * Return: .
 */

void push(stack_t **stack, unsigned int ln_cont)
{
	stack_t *new_node;
	(void) ln_cont;

	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(2);
	}

	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack)
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
	}

	*stack = new_node;
}


/**
 * pall - This function prints
 * @stack: Double pointer
 * @ln_cont: line number.
 * Return: .
 *
 */

void pall(stack_t **stack, unsigned int ln_cont)
{
	stack_t *list = *stack;
	(void) ln_cont;

	while (list)
	{
		printf("%d\n", list->n);
		list = list->next;
	}
}

/**
 * pint - This function prints
 * @stack: Double pointer
 * @ln_cont: line number.
 * Return: .
 */

void pint(stack_t **stack, unsigned int ln_cont)
{
	(void) ln_cont;

	printf("%d\n", (*stack)->n);
}

/**
 * pop - This function removes the element
 * @stack: Double pointer
 * @ln_cont: line number.
 * Return: .
 */

void pop(stack_t **stack, unsigned int ln_cont)
{
	stack_t *delete = *stack;
	(void) ln_cont;

	*stack = (*stack)->next;

	if (*stack)
		(*stack)->prev = NULL;

	delete->next = NULL;
	delete->prev = NULL;

	free(delete);
}

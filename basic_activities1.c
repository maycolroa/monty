#include "monty.h"

/**
 * swap - This function swaps the top two elements
 * @stack: Double pointer
 * @ln_cont: line number.
 * Return: .
 */

void swap(stack_t **stack, unsigned int ln_cont)
{
	int swaper;
	(void) ln_cont;

	swaper = (*stack)->next->n;

	(*stack)->next->n = (*stack)->n;
	(*stack)->n = swaper;
}

/**
 * add - This function adds to the top two elements
 * @stack: Double pointer
 * @ln_cont: Line number.
 * Return: .
 */

void add(stack_t **stack, unsigned int ln_cont)
{
	stack_t *delete = NULL;
	int sum = 0;
	(void) ln_cont;

	sum = (*stack)->n + (*stack)->next->n;

	delete = *stack;
	*stack = (*stack)->next;

	(*stack)->n = sum;
	(*stack)->prev = NULL;

	delete->next = NULL;
	free(delete);
}

/**
 * nop - .
 * @stack: Double pointer
 * @ln_cont: line number.
 * Return: .
 **/

void nop(stack_t **stack, unsigned int ln_cont)
{
	(void) stack;
	(void) ln_cont;
}

/**
 * sub - subtracts the top element
 *  @stack: Double pointer
 * @ln_cont: line number.
 * Return: .
 */

void sub(stack_t **stack, unsigned int ln_cont)
{
	stack_t *delete = NULL;
	int sub = 0;
	(void) ln_cont;

	sub = (*stack)->next->n - (*stack)->n;

	delete = *stack;
	*stack = (*stack)->next;

	(*stack)->n = sub;
	(*stack)->prev = NULL;

	delete->next = NULL;
	free(delete);
}

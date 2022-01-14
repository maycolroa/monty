#include "monty.h"

/**
 * mul - This function multiplies
 * @stack: Double pointer
 * @ln_cont: ln_cont
 * Return: .
 */

void mul(stack_t **stack, unsigned int ln_cont)
{
	stack_t *delete = NULL;
	int mul = 0;
	(void) ln_cont;

	mul = (*stack)->next->n * (*stack)->n;

	delete = *stack;
	*stack = (*stack)->next;

	(*stack)->n = mul;
	(*stack)->prev = NULL;

	delete->next = NULL;
	free(delete);
}

/**
 * mod - This function division
 * @stack: Double pointer
 * @ln_cont: line number.
 * Return: .
 */

void mod(stack_t **stack, unsigned int ln_cont)
{
	stack_t *delete = NULL;
	int mod = 0;
	(void) ln_cont;

	mod = (*stack)->next->n % (*stack)->n;

	delete = *stack;
	*stack = (*stack)->next;

	(*stack)->n = mod;
	(*stack)->prev = NULL;

	delete->next = NULL;
	free(delete);
}

/**
 * pchar -  prints the char
 * @stack: Double pointer.
 * @ln_cont: line number.
 * Return: .
 */

void pchar(stack_t **stack, unsigned int ln_cont)
{
	(void) ln_cont;

	printf("%c\n", (*stack)->n);
}

/**
 * rotl - rotates the stack
 * @stack: Double pointer
 * @ln_cont: line number.
 * Return: .
 */

void rotl(stack_t **stack, unsigned int ln_cont)
{
	stack_t *list, *end;
	(void) ln_cont;

	list = end = *stack;

	if (!*stack || !(*stack)->next)
		return;

	while (list->next)
		list = list->next;

	list->next = end;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	end->next = NULL;
}


/**
 * rotr - Rotates the stack
 * @stack: Double pointer
 * @ln_cont: line number.
 * Return: .
 *
 */

void rotr(stack_t **stack, unsigned int ln_cont)
{
	stack_t *list, *head, *turn;
	(void) ln_cont;

	if (!stack || !*stack || !(*stack)->next)
		return;

	list = head = *stack;

	while ((list->next)->next)
		list = list->next;
	turn = list->next;

	list->next = NULL;
	turn->prev = NULL;

	turn->next = head;
	head->prev = turn;
	*stack = turn;
}

#ifndef _MONTY_H_
#define _MONTY_H_
#define LIMITERS " ,!?\'\"\t\n\r"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln_cont);
} instruction_t;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int n;
void pall(stack_t **stack, unsigned int ln_cont);
void pint(stack_t **stack, unsigned int ln_cont);
void pop(stack_t **stack, unsigned int ln_cont);
void push(stack_t **stack, unsigned int ln_cont);
void swap(stack_t **stack, unsigned int ln_cont);
void add(stack_t **stack, unsigned int ln_cont);
void sub(stack_t **stack, unsigned int ln_cont);
void mul(stack_t **stack, unsigned int ln_cont);
void mod(stack_t **stack, unsigned int ln_cont);
void pchar(stack_t **stack, unsigned int ln_cont);
void nop(stack_t **stack, unsigned int ln_cont);
void pstr(stack_t **stack, unsigned int ln_cont);
void rotl(stack_t **stack, unsigned int ln_cont);
void rotr(stack_t **stack, unsigned int ln_cont);
void stack(stack_t **stack, unsigned int ln_cont);
void queue(stack_t **stack, unsigned int ln_cont);
void frees(stack_t *stack);
void comt(stack_t *head, unsigned int ln, char *token, FILE *arc_monty, int enter);
void tk_error(stack_t *stack, unsigned int number, FILE *file, char *tok);
void is_number(stack_t *stack, unsigned int lnumber, char *token, FILE *mfile);
void Manage_1(stack_t **stack, unsigned int ln_cont, FILE *m_file, int i);
int Manage_2(stack_t **stack, unsigned int ln_cont, int i);
int Manage_3(stack_t **stack, unsigned int ln_cont, int i);
int Manage_4(stack_t **stack, unsigned int ln_cont, int i);
void parse_execute(FILE *monty_file, instruction_t instructions[]);

#endif

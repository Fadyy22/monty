#include "monty.h"

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp = *stack;

	line_number = gvar.ln;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(temp);
}

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *temp = *stack;

	line_number = gvar.ln;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(temp);
}
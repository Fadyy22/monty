#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int next_number;

	line_number = gvar.ln;

	if (!(*stack) || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next_number = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = next_number;
}

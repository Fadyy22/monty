#include "monty.h"

/**
 * rotr - rotates the stack to the bottom
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (*stack)
	{
		while (temp->next != NULL)
			temp = temp->next;

		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
	}
}

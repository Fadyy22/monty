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
		free_full_command(gvar.argv);
		fclose(gvar.fd);
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
		free_full_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_full_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(temp);
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	line_number = gvar.ln;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_full_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_full_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		if (temp->n > 0 && temp->n <= 127)
		{
			printf("%c", temp->n);
			temp = temp->next;
		}
		else
			break;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (*stack && (*stack)->next != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *stack;
		(*stack)->prev = temp;
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		temp->next->next = NULL;
	}
}

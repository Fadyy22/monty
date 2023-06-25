#include "monty.h"

/**
 * _stringdup - copies a string
 *
 * @input: string to be copied
 *
 * Return: copy of the string
 */
char *_stringdup(const char *input)
{
	char *copy;
	int i;

	copy = malloc(sizeof(char) * (strlen(input) + 1));
	if (copy == NULL)
	{
		perror("malloc");
		exit(1);
	}

	for (i = 0; input[i] != '\0'; i++)
		copy[i] = input[i];

	copy[i] = '\0';
	return (copy);
}

/**
 * push - pushes an element to the stack
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	int number, i;

	line_number = gvar.ln;

	if (!gvar.argv[1])
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_full_command(gvar.argv);
		free_dlistint(*stack);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
	for (i = 0; gvar.argv[1][i] != '\0'; i++)
	{
		if (!isdigit(gvar.argv[1][i]) && gvar.argv[1][0] != 45)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_full_command(gvar.argv);
			free_dlistint(*stack);
			fclose(gvar.fd);
			exit(EXIT_FAILURE);
		}
	}
	number = atoi(gvar.argv[1]);
	add_dnodeint(stack, number);
}

/**
 * pall - prints all the values on the stack
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (*stack)
	{
		while (tmp != NULL)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	line_number = gvar.ln;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_full_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: pointer to the top pointer of the stack
 * @line_number: line number of the code
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	line_number = gvar.ln;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_full_command(gvar.argv);
		fclose(gvar.fd);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

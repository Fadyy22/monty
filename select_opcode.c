#include "monty.h"

/**
 * select_opcode - selects the right function to execute
 *
 * @code: the function's opcode
 *
 * Return: pointer to the selected function
 */
void (*select_opcode(char *code))(stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t stack_functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};

	for (i = 0; stack_functions[i].opcode; i++)
	{
		if (strcmp(stack_functions[i].opcode, code) == 0)
			break;
	}

	return (stack_functions[i].f);
}

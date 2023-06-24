#include "monty.h"

global_t gvar;
/**
 * main - monty interpreter
 *
 * @argc: number of arguments
 * @argv: passed arguments
 *
 * Return: 0 if success, 1 otherwise
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number) = NULL;
	FILE *fd;
	char line[1000];

	gvar.argv = NULL;
	gvar.ln = 1;
	gvar.top = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((fgets(line, 1000, fd)) != NULL)
	{
		gvar.argv = get_line_commands(line);
		if (!gvar.argv[0])
			continue;

		f = select_opcode(gvar.argv[0]);
		if (!f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", gvar.ln, gvar.argv[0]);
			exit(EXIT_FAILURE);
		}
		f(&gvar.top, gvar.ln);
		gvar.ln++;
	}
	return (0);
}

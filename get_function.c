#include "monty.h"

/**
 * free_full_command - free a full command  array
 *
 * @full_command: array of command
 *
 * Return: void
 */
void free_full_command(char **full_command)
{
	int i;

	i = 0;
	while (full_command[i] != NULL)
	{
		free(full_command[i]);
		i++;
	}
	free(full_command);
}

/**
 * get_line_commands - creates an array of strings from a command
 *
 * @line: line to create an array of strings from
 *
 * Return: array of strings of the full command
 */
char **get_line_commands(const char *line)
{
	char *line_cpy;
	char *command;
	char **full_command;
	char *delim = " \n\t-";
	int i;

	if (line == NULL)
		return (NULL);
	line_cpy = _stringdup(line);
	command = strtok(line_cpy, delim);
	if (command[0] == 35)
	{
		free(line_cpy);
		return (NULL);
	}
	full_command = malloc(sizeof(char *) * 3);
	if (full_command == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line_cpy);
		exit(EXIT_FAILURE);
	}
	for (i = 0; command != NULL && i < 2; i++)
	{
		full_command[i] = malloc(sizeof(char) * strlen(command) + 1);
		if (full_command[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(line_cpy);
			free_full_command(full_command);
			free(command);
			exit(EXIT_FAILURE);
		}
		strcpy(full_command[i], command);
		command = strtok(NULL, delim);
	}
	free(line_cpy);
	line_cpy = NULL;
	full_command[i] = NULL;
	return (full_command);
}

#include "main.h"
#include <stdio.h>

/**
 * append_text_to_file - function name
 * @filename: pointer to name of file
 * @text_content: string added to end of file
 *
 * Return: -1 if function fails
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int op, wt, len = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	op = open(filename, O_WRONLY | O_APPEND);
	wt = write(op, text_content, len);

	if (op == -1 || wt == -1)
		return (-1);

	close(op);

	return (1);
}

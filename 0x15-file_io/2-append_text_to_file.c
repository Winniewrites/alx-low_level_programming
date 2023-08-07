#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int da;
	size_t l;
	ssize_t wr;

	if (!filename)
	{
		return (-1);
	}

	da = open(filename, O_RDWR | O_APPEND, 0600);
	if (da == -1)
	{
		return (-1);
	}

	if (!text_content)
	{
		close(da);
		return (1);
	}

	for (l = 0; text_content[l] != '\0'; l++)
	{
		;
	}

	wr = write(da, text_content, l);
	if (wr == -1)
	{
		return (-1);
	}
	close(da);
	return (1);
}

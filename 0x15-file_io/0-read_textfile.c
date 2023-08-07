#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: name of text file
 * @letters: number of letters it should read and print.
 *
 * Return: the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t da, wr, re;
	char *buff;

	if (filename == NULL)
		return (0);

	buff = malloc(letters);
	if (buff == NULL)
		return (0);

	da = open(filename, O_RDWR);

	if (da == -1)
		return (0);

	re = read(da, buff, letters);
	if (re == -1)
		return (0);

	wr = write(STDOUT_FILENO, buff, re);
	if (wr == -1 || wr != re)
		return (0);

	re = close(da);
	if (re == -1)
		return (0);

	free(buff);
	return (wr);
}

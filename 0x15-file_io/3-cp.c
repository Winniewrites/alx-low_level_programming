#include "main.h"

#define USAGE "Usage: cp file_from file_to\n"
#define ERR_READ "Error: Can't read from file %s\n"
#define ERR_WRITE "Error: Can't write to %s\n"
#define ERR_CLOSE "Error: Can't close fd %d\n"

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	char buf[BUF_SIZE];
	int bytes, fd1, fd2;

	if (argc != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		dprintf(STDERR_FILENO, ERR_READ, argv[1]), exit(98);

	fd2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fd2 == -1)
		dprintf(STDERR_FILENO, ERR_WRITE, argv[2]), exit(99);

	while ((bytes = read(fd1, buf, BUF_SIZE)) > 0)
		if (write(fd2, buf, bytes) != bytes)
			dprintf(STDERR_FILENO, ERR_WRITE, argv[2]), exit(99);

	if (bytes == -1)
		dprintf(STDERR_FILENO, ERR_READ, argv[1]), exit(98);

	fd1 = close(fd1);
	if (fd1)
		dprintf(STDERR_FILENO, ERR_CLOSE, fd1), exit(100);

	fd2 = close(fd2);
	if (fd2)
		dprintf(STDERR_FILENO, ERR_CLOSE, fd2), exit(100);

	return (0);

}

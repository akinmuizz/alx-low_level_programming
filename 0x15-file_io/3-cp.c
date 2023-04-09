#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#define BUFF_SIZE 1024

/**
 * main - copies content of one file to the other
 * @argc: number of arguments supplied
 * @argv: Array of pointers to argument
 * description: Write a program that copies content of one file to another
 *
 * Return: exit 97
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_rd, bytes_wt;

	char buffer[BUFF_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	while ((bytes_rd = read(fd_from, setbuffer, BUFF_SIZE)) > 0)
	{
		bytes_wt = write(fd_to, buffer, bytes_rd);
		if (bytes_wt != bytes_rd)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}

	if (bytes_rd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", errno);
		exit(100);
	}

	return (0);
}

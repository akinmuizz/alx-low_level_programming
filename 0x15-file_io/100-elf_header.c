#include "main.h"
#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * elf_header - defines whether to use 32-bit or 64-bit addresses
 * error_exit - print an error message to stderr and exits
 * @message: the error message to display
 */

void error_exit(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * main - display the information contained in the ELF header of a file
 * @argc: the number of arguments (must be 2)
 * @argv: the arguments (elf_header and the name of the ELF file)
 * Return: 0 on success, or a non-zero status code on error
 */
int main(int argc, char **argv)
{
	int fd, class;
	ssize_t nread;
	Elf64_Ehdr ehdr;

	if (argc != 2)
	{
		error_exit("Usage: elf_header elf_filename");
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		error_exit("Error: Cannot read from file");
	}


	nread = read(fd, &ehdr, sizeof(ehdr));
	if (nread == -1)
	{
		error_exit("Error: Cannot read from file");
	}
	if (nread != sizeof(ehdr))
	{
		error_exit("Error: Incomplete ELF header");
	}

	if (ehdr.e_ident[EI_MAG0] != ELFMAG0 ||
			ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
			ehdr.e_ident[EI_MAG2] != ELFMAG2 ||
			ehdr.e_ident[EI_MAG3] != ELFMAG3)
		error_exit("Error: Not an ELF file");

	printf("Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", ehdr.e_ident[i]);
	printf("\nClass:   ");
	class = ehdr.e_ident[EI_CLASS];
	if (class == ELFCLASSNONE)
		printf("none\n");
	else if (class == ELFCLASS32)
		printf("ELF32\n");
	else if (class == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", class);
	printf("Data:    ");
	if (ehdr.e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (ehdr.e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", ehdr.e_ident[EI_DATA]);
	printf("Version: %d (%s)\n", ehdr.e_ident[EI_VERSION],
			ehdr.e_ident[EI_VERSION] == EV_CURRENT ? "current" : "invalid");
	printf("OS/ABI:  ");
	if (ehdr.e_ident[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (ehdr.e_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (ehdr.e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
			else
				((ehdr.e_ident[EI_OSABI]) == EI_OSABI);

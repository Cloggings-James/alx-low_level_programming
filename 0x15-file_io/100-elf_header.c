#include "main.h"
#include <elf.h>

/**
 * print_elf_header - prints the information contained in the ELF header of a file
 * @filename: the name of the file to examine
 */
void print_elf_header(const char *filename)
{
	if (filename == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Filename is NULL\n");
		exit(98);
	}

	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot open file %s\n", filename);
		exit(98);
	}

	Elf64_Ehdr header;
	ssize_t bytes_read = read(fd, &header, sizeof(header));
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot read header of file %s\n", filename);
		close(fd);
		exit(98);
	}

	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 ||
		header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", filename);
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", header.e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

	printf("  Class:                             %s\n",
		header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
		header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
		header.e_ident[EI_CLASS] == ELFCLASSNONE ? "Invalid class" :
		"Unknown");

	printf("  Data:                              %s\n",
		header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
		header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
		header.e_ident[EI_DATA] == ELFDATANONE ? "Invalid data encoding" :
		"Unknown");

	printf("  Version:                           %d%s\n",
		header.e_ident[EI_VERSION],
		header.e_ident[EI_VERSION] == EV_CURRENT ? " (current)" :
		header.e_ident[EI_VERSION] == EV_NONE ? " (invalid)" :
		"");

	printf("  OS/ABI:                            %s\n",
		header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
		header.e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
		header.e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
		header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
		header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
		header.e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
		header.e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
		header.e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "UNIX - TRU64" :
		header.e_ident[EI_OSABI] == ELFOSABI_ARM ? "ARM" :
		header.e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone App" :
		header.e_ident[EI_OSABI] == ELFOSABI_NONE ? "UNIX - System V ABI" :
		"Unknown");

	printf("  ABI Version:                       %d\n",
		header.e_ident[EI_ABIVERSION]);

	printf("  Type:                              %s\n",
		header.e_type == ET_NONE ? "NONE (No file type)" :
		header.e_type == ET_REL ? "REL (Relocatable file)" :
		header.e_type == ET_EXEC ? "EXEC (Executable file)" :
		header.e_type == ET_DYN ? "DYN (Shared object file)" :
		header.e_type == ET_CORE ? "CORE (Core file)" :
		header.e_type == ET_LOPROC ? "LOPROC (Processor-specific)" :
		header.e_type == ET_HIPROC ? "HIPROC (Processor-specific)" :
		"Unknown");

	printf("  Entry point address:               0x%lx\n",
		header.e_entry);

	printf("  Start of program headers:          %lu (bytes into file)\n",
		header.e_phoff);

	printf("  Start of section headers:          %lu (bytes into file)\n",
		header.e_shoff);

	printf("  Flags:                             0x%x\n",
		header.e_flags);

	printf("  Size of this header:               %hu (bytes)\n",
		header.e_ehsize);

	printf("  Size of program headers:           %hu (bytes)\n",
		header.e_phentsize);

	printf("  Number of program headers:         %hu\n",
		header.e_phnum);

	printf("  Size of section headers:           %hu (bytes)\n",
		header.e_shentsize);

	printf("  Number of section headers:         %hu\n",
		header.e_shnum);

	printf("  Section header string table index: %hu\n",
		header.e_shstrndx);

	close(fd);
}

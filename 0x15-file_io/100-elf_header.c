lude <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void print_elf_header(const Elf64_Ehdr *ehdr) {
    	printf("Magic: ");
    	
	for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02X ", ehdr->e_ident[i]);
    	}	
    	printf("\n");

    	printf("Class: %s\n", (ehdr->e_ident[EI_CLASS] == ELFCLASS32) ? 
		"ELF32" : "ELF64");
    	printf("Data: %s\n", (ehdr->e_ident[EI_DATA] == ELFDATA2LSB) ? 
		"2's complement, little-endian" : "Unknown");
    	printf("Version: %d\n", ehdr->e_ident[EI_VERSION]);
    	printf("OS/ABI: %s\n", (ehdr->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? 
		"UNIX - System V" : "Unknown");
    	printf("ABI Version: %d\n", ehdr->e_ident[EI_ABIVERSION]);
    	printf("Type: %s\n", (ehdr->e_type == ET_EXEC) ? 
		"EXEC (Executable file)" : "Unknown");
    	printf("Entry point address: 0x%lX\n", 
		(unsigned long)ehdr->e_entry);
	}

	int main(int argc, char *argv[]) {
    	if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    	}

    	int fd = open(argv[1], O_RDONLY);
    	if (fd == -1) {
        perror("Error opening file");
        return 98;
    	}

    	Elf64_Ehdr ehdr;
    	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr)) {
        perror("Error reading ELF header");
        close(fd);
        return 98;
    	}

    	if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Not an ELF file.\n");
        close(fd);
        return 98;
    	}	

    	print_elf_header(&ehdr);
    	close(fd);
    	return 0;
}
	

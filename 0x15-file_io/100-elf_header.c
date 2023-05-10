#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);




/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */

void check_elf(unsigned char *e_ident)
{

// Verify ELF magic number
if (!(e_ident[0] == 0x7f && e_ident[1] == 'E' && e_ident[2] == 'L' && e_ident[3] == 'F'))
{

dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);

}

}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */

void print_magic(unsigned char *e_ident)
{
int y = 0; 
printf("Magic:\t");

for (y = 0; y < EI_NIDENT; y++)
{
printf("%02x ", e_ident[y]);
}

printf("\n");
}



/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */

void print_class(unsigned char *e_ident)
{
int y = 0;
printf("Class:\t");

while (y < EI_NIDENT && e_ident[y] != ELFCLASSNONE && e_ident[y] != ELFCLASS32 && e_ident[y] != ELFCLASS64)
{
y++;
}

if (y >= EI_NIDENT)
{
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
else if (e_ident[y] == ELFCLASSNONE)
{
        printf("none\n");
    }
    else if (e_ident[y] == ELFCLASS32)
    {
        printf("ELF32\n");
    }
    else if (e_ident[y] == ELFCLASS64)
    {
        printf("ELF64\n");
    }
}



/**
 * print_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_ident)
{
    int y = 0;
printf("Data:\t\t\t\t\t");
    while (++y <= EI_DATA)
    {
        printf(" ");
    }

    switch (e_ident[EI_DATA])
    {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("<unknown: 0x%x>\n", e_ident[EI_DATA]);
    }
}




/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */

void print_version(unsigned char *e_ident)
{
    printf("Version:\t\t\t\t%d", e_ident[EI_VERSION]);

    int i = 0;
    while (++i <= EI_VERSION)
    {
        printf(" ");
    }

    switch (e_ident[EI_VERSION])
    {
        case EV_CURRENT:
            printf(" (current)\n");
            break;
        default:
            printf("\n");
            break;
    }
}



/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
    printf("OS/ABI:\t\t\t\t\t");

    if (e_ident[EI_OSABI] == ELFOSABI_NONE)
    {
        printf("UNIX - System V\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
    {
        printf("UNIX - HP-UX\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
    {
        printf("UNIX - NetBSD\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
    {
        printf("UNIX - Linux\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
    {
	    printf("UNIX - Solaris\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
    {
        printf("UNIX - IRIX\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
    {
        printf("UNIX - FreeBSD\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
    {
        printf("UNIX - TRU64\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
    {
        printf("ARM\n");
    }
    else if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
    {
        printf("Standalone App\n");
    }
    else
    {
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
    int abi_version = e_ident[EI_ABIVERSION];
    printf("  ABI Version:                       ");
    if (abi_version == 0)
        printf("0 (current)\n");
    else
        printf("%d\n", abi_version);
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	char *type_names[] = {
		"NONE (None)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};

	if (e_type < sizeof(type_names)/sizeof(type_names[0]))
	{
		printf("  Type:                              %s\n", type_names[e_type]);
	}
	else
	{
		printf("  Type:                              <unknown: %x>\n", e_type);
	}
}



/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
    char format_string[10];
    snprintf(format_string, sizeof(format_string), "  Entry point address:               %%#%dlx\n", e_ident[EI_CLASS] == ELFCLASS32 ? 8 : 16);
    printf(format_string, e_entry);
}



/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        printf("Error: Can't close fd %d\n", elf);
        exit(98);
    }
}



/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int argc, char *argv[])
{
    Elf64_Ehdr header;
    unsigned char *ptr = (unsigned char *)&header;
    int o, r, count = 0;

    o = open(argv[1], O_RDONLY);
    if (o == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    while (count < sizeof(header))
    {
        r = read(o, ptr, sizeof(header) - count);
        if (r == -1)
        {
            close_elf(o);
            dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
            exit(98);
        }
        }
        ptr += r;
        count += r;
    }

    check_elf(header.e_ident);
    printf("ELF Header:\n");
    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    print_abi(header.e_ident);
    print_type(header.e_type, header.e_ident);
    print_entry(header.e_entry, header.e_ident);

    close_elf(o);
    return (0);
}

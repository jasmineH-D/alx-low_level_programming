#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void close_file(FILE *fp);

int main(int argc, char *argv[])
{
if (argc != 3)
{
fprintf(stderr, "Usage: cp source_file destination_file\n");
exit(EXIT_FAILURE);
}

FILE *source_fp = fopen(argv[1], "r");
if (!source_fp)
{
fprintf(stderr, "Error: Cannot open source file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

FILE *dest_fp = fopen(argv[2], "w");
if (!dest_fp)
{
fprintf(stderr, "Error: Cannot create or open destination file %s\n", argv[2]);
close_file(source_fp);
exit(EXIT_FAILURE);
}
char buffer[BUFFER_SIZE];
size_t bytes_read;

while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, source_fp)) > 0)
{
if (fwrite(buffer, sizeof(char), bytes_read, dest_fp) != bytes_read)
{
fprintf(stderr, "Error: Cannot write to destination file %s\n", argv[2]);
close_file(source_fp);
close_file(dest_fp);
exit(EXIT_FAILURE);
}
}

close_file(source_fp);
close_file(dest_fp);

return (0);
}

void close_file(FILE *fp)
{
if (fclose(fp) != 0)
{
fprintf(stderr, "Error: Cannot close file\n");
exit(EXIT_FAILURE);
}
}

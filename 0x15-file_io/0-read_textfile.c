#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints its contents to STDOUT.
 * @filename: Text file to be read.
 * @letters: Number of letters to be read.
 * Return: The actual number of bytes read and printed (w)
 * or if the function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w, t;

	if (filename == NULL)
		exit(1);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		exit(1);

	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}

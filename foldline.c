#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

void usage()
{
	write(STDERR_FILENO, "Usage: foldline [-n check_size]\n", 32);
}

int main(int argc, char *argv[])
{
	size_t buf_len = 4;
	if (argc == 3 && strcmp(argv[1], "-n") == 0) {
		buf_len = atoi(argv[2]);
	} else if (argc == 2 && (strcmp(argv[1], "-h") == 0
			         || strcmp(argv[1], "--help") == 0)) {
		usage();
		exit(0);
	} else if (argc != 1) {
		usage();
		exit(-1);
	}
	char* prefix = malloc(buf_len);

	char* line = NULL;
	size_t n = 0, bufsize = 0;
	while((n = getline(&line, &bufsize, stdin)) != -1) {
		if (strncmp(line, prefix, MIN(buf_len, n)) == 0)
			write(STDOUT_FILENO, "\033[F\033[K", 6);
		write(STDOUT_FILENO, line, n);
		strncpy(prefix, line, MIN(buf_len, n));
	}
	free(line);
	free(prefix);
	return 0;
}

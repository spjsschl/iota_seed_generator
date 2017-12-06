#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifdef __MINGW32__
#define _CRT_RAND_S
#endif

#include <stdlib.h>

#ifdef __MINGW32__
static int
windows_random_bytes(uint8_t *buffer, int len)
{
	unsigned int number;
	int i, j, k, err;

	k = 0;
	for (i = 0; i < len; i += sizeof(number)) {
		err = rand_s(&number);
		if (err != 0) {
			return -1;
		}
		for (j = 0; j < sizeof(number); j++) {
			buffer[k++] = ((uint8_t *) &number)[j];
			if (k == len) {
				break;
			}
		}
	}
	return 0;
}

#else

static int
linux_random_bytes(uint8_t *buffer, int len)
{
	ssize_t rread;
	int fd, total;

	fd = open("/dev/random", O_RDONLY);
	total = 0;
	while (total < len) {
		rread = read(fd, buffer + total, len - total);
		if (rread == -1) {
			close(fd);
			return -1;
		} else {
			total += rread;
		}
	}
	close(fd);
	return 0;
}
#endif

int
main(int argc, char **argv)
{
	const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ9";
	uint8_t rand[81];
	char res[82];
	int i;

#ifdef __MINGW32__
	if (windows_random_bytes(rand, 81) != 0) {
#else
	if (linux_random_bytes(rand, 81) != 0) {
#endif
		perror(NULL);
		fprintf(stderr, "Could not get random bytes\n");
		exit (EXIT_FAILURE);
	}

	for (i = 0; i < 81; i++) {
		res[i] = chars[rand[i] % 27];
	}
	res[82] = '\0';
	printf("Generated seed:\n");
	printf("%s\n", res);
	exit(EXIT_SUCCESS);
}

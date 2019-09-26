#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char string1[128] = "some string";
char string2[128];

int main(int argc, char const *argv[]) {
	char inbuf[128];
	int p[2];

	if (pipe(p) < 0)
		exit(1);

	if (fork() > 0) {
		close(p[0]);
		write(p[1], string1, 128);
		close(p[1]);
		printf("parent s1: %s\n", string1);
		printf("parent s2: %s\n", string2);
	}
	else {
		close(p[1]);
		read(p[0], string2, 128);
		close(p[0]);
		printf("child s1: %s\n", string1);
		printf("child s2: %s\n", string2);
	}

	return 0;
}
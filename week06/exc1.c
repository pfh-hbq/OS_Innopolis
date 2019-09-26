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

	printf("s1: %s\n", string1);
	printf("s2: %s\n", string2);

	write(p[1], string1, 128);

	read(p[0], string2, 128);
	
	printf("s1: %s\n", string1);
	printf("s2: %s\n", string2);

	return 0;
}
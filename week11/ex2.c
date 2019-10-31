#include <stdio.h>
#include <unistd.h>

int main() {
	
	setvbuf(stdout, 0, _IOLBF, 6);
	
	printf("%c", 'H');
	sleep(1);

	printf("%c", 'e');
	sleep(1);

	printf("%c", 'l');
	sleep(1);

	printf("%c", 'l');
	sleep(1);

	printf("%c", 'o');

	return 0;
}
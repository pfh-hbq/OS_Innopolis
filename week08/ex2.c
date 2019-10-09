#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
	
	for (int i = 0; i < 10; ++i) {
		memset(malloc(1024*1024*10), 0, 1024*1024*10);

		sleep(1);
	}

	return 0;
}
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main(int argc, char const *argv[]) {
	
	struct rusage bufMem;

	for (int i = 0; i < 10; ++i) {
		memset(malloc(1024*1024*10), 0, 1024*1024*10);

		getrusage(RUSAGE_SELF,&bufMem);
		printf("Memory usage: %ld\n", bufMem.ru_maxrss);

		sleep(1);
	}

	return 0;
}
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
	
	for (int i = 0; i < 3; ++i) {
		fork();
		sleep(5);
	}

	return 0;
}

// each process creates 2 more processes
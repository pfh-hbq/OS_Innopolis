#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void message() {
	printf(" Sorry, CTRL+C does not work\n");
}

int main(int argc, char const *argv[]) {
	
	signal(SIGINT, message);

	while(1) {

	}

	return 0;
}
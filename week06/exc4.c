#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void messageKill() {
	printf(" Killed\n");
}

void messageStop() {
	printf(" Stopped\n");
}

void messageUsr1() {
	printf(" Usr1ed\n");
}

int main(int argc, char const *argv[]) {

	// Handler won't execute, because cannot be caught or ignored
	signal(SIGKILL, messageKill);
	signal(SIGSTOP, messageStop);

	// Handler will be executed when it would receive signal
	signal(SIGUSR1, messageUsr1);

	while(1) {

	}

	return 0;
}
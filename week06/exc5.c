#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void messageTerminate() {
	printf("I'm dead\n");
	exit(0);
}

int main(int argc, char const *argv[]) {

	signal(SIGTERM, messageTerminate);

	pid_t pid = fork();

	if (pid > 0) {
		sleep(10);
		kill(pid, SIGTERM);
	}
	else {
		while (1) {
			printf("I'm alive\n");
			sleep(1);
		}
	}

	return 0;
}
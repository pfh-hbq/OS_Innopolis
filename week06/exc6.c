#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void message() {
	printf("I'm dead\n");
	exit(0);
}

int main(int argc, char const *argv[]) {

	int fd1[2], fd2[2];
	pipe(fd1);
	pipe(fd2);

	pid_t pidFirst = 1;
	pid_t pidSecond = 1;

	pidFirst = fork();

	if (!pidFirst) {
		pid_t rec;
		read(fd1[0], &rec, sizeof(rec));

		printf("Sleep\n");
		sleep(5);

		printf("Child killed\n");
		kill(rec, SIGINT);
	} else {
		pidSecond = fork();
	}

	if (!pidSecond) {
		signal(SIGINT, message);
		while (1) {
			printf("I'm alive\n");
			sleep(1);
		}
	}

	if (pidFirst) {
		printf("Send pidSecond to 1st child\n");
		write(fd1[1], &pidSecond, sizeof(pidSecond));
		close(fd1[1]);
		waitpid(pidSecond, 0, 0);
	}

	return 0;
}
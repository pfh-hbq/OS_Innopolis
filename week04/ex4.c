#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

	char command[1024] = {};

	while (1) {
		fgets(command, 1024, stdin);

		system(command);

		if (strcmp(command, "exit\n") == 0)
			break;
	}

	return 0;
}
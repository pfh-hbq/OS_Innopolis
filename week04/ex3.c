#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

	char command[1024] = {};
	
	while (1) {
		scanf("%s", command);
		system(command);

		if (strcmp(command, "exit") == 0)
			break;
	}

	return 0;
}
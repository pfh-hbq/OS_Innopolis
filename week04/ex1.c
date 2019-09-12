#include <stdio.h>
#include <unistd.h>

void childProcess(int n);
void parentProcess(int n);

int main(int argc, char const *argv[]) {
	int k  = fork();

	int n = getpid();

	if (k == 0)
		childProcess(n);
	else
		parentProcess(n);

	return 0;
}

void childProcess(int n) {
	printf("Hello from parent [PID - %d]\n", n);
}

void parentProcess(int n) {
	printf("Hello from child [PID - %d]\n", n);
}

//child execution starts after parent, while parent continues immediately

//Outputed:

/*
1 execution
Hello from child [PID - 63018]
2 execution
Hello from parent [PID - 63019]
Hello from child [PID - 63020]
3 execution
Hello from parent [PID - 63021]
Hello from child [PID - 63022]
4 execution
Hello from parent [PID - 63023]
Hello from child [PID - 63024]
5 execution
Hello from parent [PID - 63025]
Hello from child [PID - 63026]
6 execution
Hello from parent [PID - 63027]
Hello from child [PID - 63028]
7 execution
Hello from parent [PID - 63029]
Hello from child [PID - 63030]
8 execution
Hello from parent [PID - 63031]
Hello from child [PID - 63032]
9 execution
Hello from parent [PID - 63033]
Hello from child [PID - 63034]
10 execution
Hello from parent [PID - 63035]
Hello from child [PID - 63036]
Hello from parent [PID - 63037]
*/
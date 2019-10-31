#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(){

	int file = open("ex1.txt", O_RDWR);

	char *text = "This is a nice day";

	struct stat st;
	stat("ex1.txt", &st);

	size_t size = st.st_size;

	char *addr;
	addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);

	for (int i = 0; i < size; ++i)
		addr[i] = text[i];

	return 0;
}
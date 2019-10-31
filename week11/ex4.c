#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {
	int sfd, dfd;
	char *src, *dest;
	size_t fSize;

	sfd = open("ex1.txt", O_RDONLY);
	fSize = lseek(sfd, 0, SEEK_END);
	
	src = mmap(NULL, fSize, PROT_READ, MAP_PRIVATE, sfd, 0);
	dfd = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
	
	ftruncate(dfd, fSize);
	
	dest = mmap(NULL, fSize, PROT_READ | PROT_WRITE, MAP_SHARED, dfd, 0);
	
	memcpy(dest, src, fSize);
	munmap(src, fSize);
	munmap(dest, fSize);
	
	close(sfd);
	close(dfd);

	return 0;
}
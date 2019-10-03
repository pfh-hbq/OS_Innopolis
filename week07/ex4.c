#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc/malloc.h>

void *realloc1(void *ptr, size_t size) {
	void *new_ptr;

	if (size == 0) {
		free(ptr);
		return NULL;
	}
	if (ptr == NULL) {
		new_ptr = malloc(size);
	} else {
		if (malloc_size(ptr) < size) {
			new_ptr = malloc(size);
			memcpy(new_ptr, ptr, malloc_size(ptr));
			free(ptr);
		} else {
			new_ptr = ptr;
		}
	}
	return new_ptr;
}

int main() {
	int n = 10;
	int *a1 = malloc(n*sizeof(int));
	
	for(int i = 0; i < n; i++){
		a1[i]=100;

		printf("%d ", a1[i]);
	}
	printf("\n");

	int n2 = 15;
	a1 = (int *)realloc(a1, n2*sizeof(int));

	for (int i = n; i < n2; ++i) {
		a1[i] = 0;
	}

	for(int i = 0; i < n2; i++){
		printf("%d ", a1[i]);
	}
	printf("\n");

	free(a1);

	return 0;
}
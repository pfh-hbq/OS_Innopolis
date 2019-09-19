#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 3

pthread_t thread_id[NUM_THREADS];

void * PrintHello(int i) {
	printf("Thread %d. Iteration %d.\n", (int) pthread_self(), i);

	pthread_exit(NULL);
}

int main(int argc, char * argv[]) {
	int rc;
	
	for (int i = 0; i < NUM_THREADS; i++) {
 		
 		rc = pthread_create(&thread_id[i], NULL, PrintHello, i);
 		
 		if (rc) {
 			printf("\n ERROR: return code from pthread_create is %d.\n", rc);
 			exit(1);
 		}
		
		printf("\nThread %d. Created new thread (%d), iteration %d.\n", (int) pthread_self(), (int) thread_id[i], i);
 		
 		if (i % 5 == 0)
 			sleep(1);

 		// threads are now execute in a certain order.
 		pthread_join(thread_id[i], NULL);
 	}
 	
 	pthread_exit(NULL);
}
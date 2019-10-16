#include <stdio.h>
#include <limits.h>

int pageFrames;

int searchInFrame(int pageNum, int frame[]) {
	for (int i = 0; i < pageFrames; ++i)
		if (frame[i] == pageNum)
			return 1;

	return 0;
}

int findMostAged(int age[]) {
	int min = INT_MAX;
	int mAged = 0;

	for (int i = 0; i < pageFrames; ++i) {
		if (age[i] < min) {
			min = age[i];
			mAged = i;
		}
	}

	return mAged;
}

void shiftAge(int age[], int pageNum, int frame[]) {
	for (int i = 0; i < pageFrames; ++i) {
		if (frame[i] == pageNum)
			age[i] = INT_MAX;
		else
			age[i] = age[i] >> 1;
	}
}

int main() {
	printf("Number of page frames: ");
	long long hit;
	long long miss;

	scanf("%d", &pageFrames);
	int frame[pageFrames];
	int age[pageFrames];

	for (int i = 0; i < pageFrames; ++i)
		frame[i] = 0;

	for (int i = 0; i < pageFrames; ++i)
		age[i] = 0;

	FILE *file = fopen("Lab 09 input.txt", "r");
	int pageNum;

	while (!feof(file)) {
		fscanf(file, "%d", &pageNum);

		int isHitted = searchInFrame(pageNum, frame);

		if (isHitted) {
			hit++;
			shiftAge(age, pageNum, frame);
		} else {
			miss++;
			int mostAged = findMostAged(age);
			frame[mostAged] = pageNum;
			age[mostAged] = 0;
			shiftAge(age, pageNum, frame);
		}
	}

	printf("Hit: %lld\n", hit);
	printf("Miss: %lld\n", miss);
	printf("Hit/Miss ratio: %lf\n", (hit * 1.0) / (miss * 1.0));

	fclose(file);
}

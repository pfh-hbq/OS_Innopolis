#include <stdio.h>
#include <string.h>

int main() {
	char s[256] = {};

	scanf("%[^\n]", s);

	int len = strlen(s);
	
	for (int i = 0; i < len / 2; ++i) {
		char k = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = k;
	}

	printf("%s\n", s);

	return 0;
}
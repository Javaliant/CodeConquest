/* Author: Luigi Vincent
*
*/

#include <stdio.h>

void print_buzzified(int fizz, int buzz, int count) {
	for (int i = 1; i <= count; i++) {
		if (i % fizz == 0 && i % buzz == 0) {
			printf("%s", "FB");
		} else if (i % fizz == 0) {
			printf("%s", "F");
		} else if (i % buzz == 0) {
			printf("%s", "B");
		} else {
			printf("%d", i);
		}

		printf(i < count ? " " : "\n");
	}
}

int main(int argc, const char * argv[]) {
	FILE *file;
	if (argc < 2 || !(file = fopen(argv[1], "r"))) {
		puts("No argument provided / File not found.");
		return 1;
	}

	file = fopen(argv[1], "r");
	int fizz;
	int buzz;
	int count;

	while (!feof(file)) {
		fscanf(file, "%d %d %d", &fizz, &buzz, &count);
		print_buzzified(fizz, buzz, count);
	}

	fclose(file);
}
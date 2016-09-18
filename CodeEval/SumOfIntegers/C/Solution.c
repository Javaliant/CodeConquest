/* Author: Luigi Vincent 
*
*/

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024
#define MIN_INT -32768

int largest_contiguous_sum(int *array, int size) {
	int max = MIN_INT;
	int current_max = MIN_INT;
	for (int i = 0; i < size; i++) {
		current_max = current_max + array[i] > array[i] ? current_max + array[i] : array[i];
		max = max > current_max ? max : current_max;
	}
	return max;
}

int compute_largest_contiguous_sum(char *line) {
	char seperator[] = ",";
	char *token;
	int var;
	int array[512];
	int i = 0;

	token = strtok(line, seperator);
	while (token != NULL) {
	    sscanf(token, "%d", &var);
	    array[i++] = var;
	    token = strtok(NULL, seperator);
	}

	return largest_contiguous_sum(array, i);
}

int main(int argc, char *args[]) {
	if (argc < 2) {
		fprintf(stderr, "File path not provided. Exiting...\n");
		return 1;
	}

	if (argc > 2) {
		puts("Excessive arguments, only the first will be considered.");
	}

	FILE *file = fopen(args[1], "r");
	if (file == NULL) {
		perror("Error");
		return 1;
	}

	char line[LINE_LENGTH];
	while (fgets(line, LINE_LENGTH, file)) {
		printf("%d\n", compute_largest_contiguous_sum(line));
	}

	fclose(file);
}
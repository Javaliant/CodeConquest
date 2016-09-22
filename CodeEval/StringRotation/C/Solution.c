/* Author: Luigi Vincent 
*
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 64

char* str_mul(char* str, int times) {
	char *string_multiplied = malloc(sizeof(str) * times + 1);
	for (int i = 1; i <= times; i++) {
		strcat(string_multiplied, str);
	}
	return string_multiplied;	
}

bool is_rotated(char *original, char *test_case) {
	int original_length = strlen(original);
	char *rotation_superset = str_mul(original, 2);
	bool is_substring = strstr(rotation_superset, test_case) != NULL;
	return original_length == strlen(test_case) && is_substring;
}

char* parse_and_evaluate(char *line) {
	const char tokens[] = ",\n\r";
	char *original = strtok(line, tokens);
	char *test_case = strtok(NULL, tokens);
	return is_rotated(original, test_case) ? "True" : "False";
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
		printf("%s\n", parse_and_evaluate(line));
	}

	fclose(file);
}
/* Author: Luigi Vincent 
*
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 64

void str_mul(char *str, char *string_multiplied, int times) {
    string_multiplied[0] = '\0';
    for (int i = 1; i <= times; i++) {
        strcat(string_multiplied, str);
    }
}

bool is_rotated(char *original, char *test_case) {
    if (strlen(original) != strlen(test_case)) {
    	return false;
    }
    char rotation_superset[LINE_LENGTH * 2];
    str_mul(original, rotation_superset, 2);
    return strstr(rotation_superset, test_case) != NULL;
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
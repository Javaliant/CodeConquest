/* Author: Luigi Vincent 
*
*/

#include <stdio.h>
#include <ctype.h>

#define LINE_LENGTH 42

char* find_seperator(char line[]) {
	for (int i = 0; i < LINE_LENGTH; i++) {
		if (line[i] == ' ') {
			return &line[i];
		}
	}
}

void encode_mask(char line[LINE_LENGTH], char *mask) {
	for (int i = 0; line[i] != '\0'; i++) {
		if (*mask++ == '1') {
			line[i] = toupper(line[i]);
		}
	}
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
		char *mask = find_seperator(line);
		*mask++ = '\0';
		encode_mask(line, mask);
		puts(line);
	}

	fclose(file);
}
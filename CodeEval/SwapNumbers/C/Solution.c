/* Author: Luigi Vincent 
*
*/

#include <stdio.h>
#include <ctype.h>

#define LINE_BUFFER 256

void swapNumbers(char line[LINE_BUFFER]) {
	char *position = NULL;
	for (int i = 0; i < LINE_BUFFER; i++) {
		if (isdigit(line[i])) {
			if (position == NULL) {
				position = &line[i];
			} else {
				int temp = *position;
                *position = line[i];
                line[i] = temp;
                position = NULL;
			}
		}
	}
}

int main(int argc, char *args[]) {
	if (argc < 2) {
		puts("File path not provided.");
		return 1;
	}

	if (argc > 2) {
		puts("Excessive arguments, only the first will be considered.");
	}

	FILE *file = fopen(args[1], "r");
    if (file == NULL) {
        puts("Could not access file / file not found.");
        return 1;
    }

	char line[LINE_BUFFER];
	while (fgets(line, LINE_BUFFER, file)) {
		swapNumbers(line);
		printf("%s", line);
	}

	fclose(file);
}
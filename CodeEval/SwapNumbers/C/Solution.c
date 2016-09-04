/* Author: Luigi Vincent 
*
*/

#include <stdio.h>
#include <ctype.h>

#define LINE_BUFFER 128

int fileExists(char *filename) {
	FILE *file = fopen(filename, "r");
	if (file != NULL) {
		fclose(file);
	}
	return file != NULL;
}

void swapNumbers(char line[LINE_BUFFER]) {
	int temp = 0;
	int position = 0;
	int swapped = 0;

	for (int i = 0; i < LINE_BUFFER; i++) {
		if (isdigit(line[i])) {
			if (!swapped) {
				position = i;
				temp = line[i];
				swapped = 1;
			} else {
				line[position] = line[i];
				line[i] = temp;
				swapped = 0;
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

	if (!fileExists(args[1])) {
		puts("Could not access file / file not found.");
		return 1;
	}

	FILE *file = fopen(args[1], "r");
    char line[LINE_BUFFER];

    while (fgets(line, LINE_BUFFER, file)) {
    	swapNumbers(line);
        printf("%s", line);
    }

    fclose(file);
}
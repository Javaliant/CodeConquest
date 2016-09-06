/* Author: Luigi Vincent 
*
*/

#include <stdio.h>
#include <ctype.h>

#define LINE_BUFFER 42

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
		for (int i = 0, word_length = 0; ; i++, word_length++) {
			if (line[i] == ' ') {
				line[i++] = '\0';
				for (int j = 0; j < word_length; j++, i++) {
					if (line[i] == '1') {
						line[j] = toupper(line[j]);
					}
				}
				printf("%s\n", line);
				break;
			}
		}
	}

	fclose(file);
}
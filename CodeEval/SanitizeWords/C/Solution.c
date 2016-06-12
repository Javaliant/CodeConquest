/* Author: Luigi Vincent
*
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define LINE_BUFFER 100

void sanitize(char * input) {
	int iterator = 0;
	bool match_found = false;
	bool space_needed = false;

	for (int i = 0; input[i] != '\0'; i++) {
		if (isalpha(input[i])) {
			if (space_needed) {
				input[iterator++] = ' ';
				space_needed = false;
			}

			input[iterator++] = tolower(input[i]);
			match_found = true;
		} else if (match_found) {
			match_found = false;
			space_needed = true;
		}
	}

	input[iterator] = '\0';
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_BUFFER];

    while (fgets(line, LINE_BUFFER, file)) {
    	sanitize(line);
        printf("%s\n", line);
    }

    return 0;
}
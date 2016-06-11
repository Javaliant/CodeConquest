/* Author: Luigi Vincent
*
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define LINE_MEMORY 1024

void to_lowercase(char * input) {
	for(int i = 0; input[i]; i++){
  		input[i] = tolower(input[i]);
	}
}

void sanitize(char * input, char *destination, int destinationSize) {
	int iterator = 0;
	int character_value;
	bool match_found = false;

	for (int i = 0; i < strlen(input); i++) {
		if (input[i] >= 'a' && input[i] <= 'z'
		||  input[i] >= 'A' && input[i] <= 'Z') {
			destination[iterator++] = input[i];
			match_found = true;
		} else if (match_found) {
			match_found = false;
			destination[iterator++] = ' ';
		}
	}

	destination[iterator] = '\0';
	to_lowercase(destination);
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_MEMORY];
    char sanitized[LINE_MEMORY];

    while (fgets(line, LINE_MEMORY, file)) {
    	sanitize(line, sanitized, LINE_MEMORY);
        printf("%s\n", sanitized);
    }

    return 0;
}
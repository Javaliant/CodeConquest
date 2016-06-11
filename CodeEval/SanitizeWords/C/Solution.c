/* Author: Luigi Vincent
*
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void to_lowercase(char * input) {
	for(int i = 0; input[i]; i++){
  		input[i] = tolower(input[i]);
	}
}

char * sanitize(char * input) {
	char *sanitized = malloc(sizeof (char) * 1024);
	int iterator = 0;
	int character_value;
	bool wordMatched = false;

	for (int i = 0; i < strlen(input); i++) {
		int character_value = input[i];
		// a-z = 97-122, A-Z = 65-90
		if (character_value >= 97 && character_value <= 122 || character_value >= 65 && character_value <= 90) {
			sanitized[iterator++] = input[i];
			wordMatched = true;
		} else if (wordMatched) {
			wordMatched = false;
			sanitized[iterator++] = ' ';
		}
	}

	sanitized[iterator] = '\0';
	to_lowercase(sanitized);
	return sanitized;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    while (fgets(line, 1024, file)) {
        printf("%s\n", sanitize(line));
    }

    return 0;
}
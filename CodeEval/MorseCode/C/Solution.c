/* Author: Luigi Vincent
*
*/

#include <stdio.h>
#include <string.h>

#define LINE_BUFFER 128
#define ALPHABET_LENGTH 37

const char alphabet[ALPHABET_LENGTH] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const char *morse[ALPHABET_LENGTH] = {
	".-",
	"-...",
	"-.-.",
	"-..",
	".",
	"..-.",
	"--.",
	"....",
	"..",
	".---",
	"-.-",
	".-..",
	"--",
	"-.",
	"---",
	".--.",
	"--.-",
	".-.",
	"...",
	"-",
	"..-",
	"...-",
	".--",
	"-..-",
	"-.--",
	"--..",
	"-----",
	".----",
	"..---",
	"...--",
	"....-",
	".....",
	"-....",
	"--...",
	"---..",
	"----."
};

void print_converted_char(char *code) {
	for (int i = 0; i < ALPHABET_LENGTH; i++) {
		if (strcmp(code, morse[i]) == 0) {
			printf("%c", alphabet[i]);
			break;
		}
	}
}

void print_converted_word(char *word) {
	char *code = strtok(word, " ");
	while (code != NULL) {
		print_converted_char(code);
		code = strtok(NULL, " ");
	}
	printf(" ");
}

void print_converted(char *line) {
	char *word = strtok(line, ";");
	while (word != NULL) { // the issue is with the way strtok works.
		print_converted_word(word);
		word = strtok(NULL, ";");
	}
	printf("\n");
}

// void print_converted(char *line) {
// 	char word[LINE_BUFFER];

// 	for (int i = 0, j = 0; i < LINE_BUFFER; i++) {
// 		if (line[i] == ';') {
// 			word[j] = '\0';
// 			print_converted_word(word);
// 			j = 0;
// 			i += 2;
// 			continue;
// 		} else {
// 			word[j++] = line[i];
// 		}
// 	}

// 	printf("\n");
// }

void deliminate(char *line, char delimiter) {
	for (int i = 0; i < LINE_BUFFER; i++) {
		if (line[i] == ' ' && line[i + 1] == ' ') {
			line[i] = delimiter;
			line[i + 1] = delimiter;
		}
	}
}

int main(int argc, const char *argv[]) {
	FILE *file;
	if (argc < 2 || !(file = fopen(argv[1], "r"))) {
		puts("No argument provided / File not found.");
		return 1;
	}

	file = fopen(argv[1], "r");
	char line[LINE_BUFFER];
	while (fgets(line, LINE_BUFFER, file)) {
		deliminate(line, ';');
		print_converted(line);
	}
}
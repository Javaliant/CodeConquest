/* Author: Luigi Vincent
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_BUFFER 128

void initialize(char lines_to_print[][LINE_BUFFER], int number_of_lines, FILE *file) {
	for (int i = 0; i < number_of_lines; i++) {
		fgets(lines_to_print[i], LINE_BUFFER, file);
	}
}

int compare(const void *first_line, const void *second_line) {
	size_t first_line_length = strlen(first_line);
	size_t second_line_length = strlen(second_line);
	// Descending order
	return first_line_length < second_line_length;
}

void sort_lines(char lines_to_print[][LINE_BUFFER], int number_of_lines) {
	qsort(lines_to_print, number_of_lines, LINE_BUFFER, compare);
}

void print_lines(char lines_to_print[][LINE_BUFFER], int number_of_lines) {
	for (int i = 0; i < number_of_lines; i++) {
		fputs(lines_to_print[i], stdout);
	}
}

int main(int argc, const char * argv[]) {
	FILE *file;
	if (argc < 2 || !(file = fopen(argv[1], "r"))) {
		puts("No argument provided / File not found.");
		return 1;
	}

	file = fopen(argv[1], "r");
	char line[LINE_BUFFER];
	fgets(line, LINE_BUFFER, file);
	int number_of_lines = atoi(line);

	char lines_to_print[number_of_lines][LINE_BUFFER];
	initialize(lines_to_print, number_of_lines, file);
	sort_lines(lines_to_print, number_of_lines);

	int end = number_of_lines - 1;
	int shortest_long_line_length = strlen(lines_to_print[end]);
	int line_length;
	while (fgets(line, LINE_BUFFER, file)) {
		if ((line_length = strlen(line)) > shortest_long_line_length) {
			strcpy(lines_to_print[end], line);
			sort_lines(lines_to_print, number_of_lines);
			shortest_long_line_length = strlen(lines_to_print[end]);
		}
	}
	
	print_lines(lines_to_print, number_of_lines);
	return 0;
}
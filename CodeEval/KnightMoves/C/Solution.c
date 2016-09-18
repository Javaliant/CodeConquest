/* Author: Luigi Vincent 
*
*/

#include <stdio.h>
#include <stdlib.h>

#define LINE_LENGTH 5
#define BOARD_LENGTH 8
#define MOVE_BUFFER 24

int rows[] = {1, 2, 3, 4, 5, 6, 7, 8};
char cols[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
char moves[MOVE_BUFFER];
int move_iter = 0;

char num_convert(int *n) {
	for (int i = 0; i < BOARD_LENGTH; i++) {
		if (*n == rows[i]) {
			return cols[i];
		}
	}
}

int alpha_convert(char *c) {
	for (int i = 0; i < BOARD_LENGTH; i++) {
		if (*c == cols[i]) {
			return rows[i];
		}
	}
}

void add_moves(int c, int n1, int n2) {
	if (c >= 1 && c <= 8) {
		if (n1 >= 1) {
			moves[move_iter++] = num_convert(&c);
			moves[move_iter++] = n1 + '0';
			moves[move_iter++] = ' ';
		}
		if (n2 <= 8) {
			moves[move_iter++] = num_convert(&c);
			moves[move_iter++] = n2 + '0';
			moves[move_iter++] = ' ';
		}
	}
}

char* valid_moves(char position[]) {
	int C = alpha_convert(&position[0]);
	int N = atoi(&position[1]);

	add_moves(C - 2, N - 1, N + 1);
	add_moves(C - 1, N - 2, N + 2);
	add_moves(C + 1, N - 2, N + 2);
	add_moves(C + 2, N - 1, N + 1);

	moves[move_iter - 1] = '\0';
	move_iter = 0;
	return moves;
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

	char position[LINE_LENGTH];
	while (fgets(position, LINE_LENGTH, file)) {
		puts(valid_moves(position));
	}

	fclose(file);
}
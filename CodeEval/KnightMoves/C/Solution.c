/* Author: Luigi Vincent
*
*/

#include <stdio.h>
#include <stdbool.h>

#define LINE_LENGTH 5
#define NUMBER_OF_KNIGHT_MOVES 8

typedef struct {
	signed char column;
	int row;
} Position;

Position knight_moves[] = {
	{-2, -1}, 
	{-2, +1}, 
	{-1, -2}, 
	{-1, +2}, 
	{+1, -2}, 
	{+1, +2}, 
	{+2, -1}, 
	{+2, +1} 
};

void position_sum(Position *sum, Position *piece, Position *potential_move) {
    sum->column = piece->column + potential_move->column;
    sum->row = piece->row + potential_move->row;
}

bool in_chessboard(Position *position) {
    return position->column >= 'a'
        && position->column <= 'h'
        && position->row >= 49
        && position->row <= 56;
}

void print_valid_moves(char *position) {
	Position knight = {position[0], position[1]};
	Position sum;
	for (int i = 0; i < NUMBER_OF_KNIGHT_MOVES; i++) {
			position_sum(&sum, &knight, &knight_moves[i]);
			if (in_chessboard(&sum)) {
				printf("%c%c ", sum.column, sum.row);
			}
		}
	printf("\n");
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
		print_valid_moves(position);
	}

	fclose(file);
}
#include "head.h"



//// Ask function for line and column //////////////////

int ask_line (int line_max){
/* Ask the user to input a number */
	int line = -1;
	while( line < 0 || line >= line_max){
		
		printf("Number of the line ? (must be < %d) ", line_max);	
		scanf("%d", &line);
		clear(stdin);
	}
	return line;
}

int ask_col(int col_max){
/* Ask the user to input a letter */
	int column = 64;
	while(column < 65|| column >= 65+col_max){
		printf("Column ? (must be < %c) ", 65+col_max);
		scanf(" %c", &column);
		clear(stdin);
	}
	return column;
}

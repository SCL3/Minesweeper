#include "head.h"


//// count_bomb //////////////////////////////////////////////


// This function adds +1 to every bomb-cell's neighbors.
void count_bomb(Cell** table, int nmb_lines, int nmb_colomns){	
	for(int i=0; i<nmb_colomns;i++){
		for(int j=0; i<nmb_lines; i++){
			table[i][j].counter = 0;
		}
	}
	for(int i=0; i<nmb_lines;i++){
		for(int j=0; j<nmb_colomns; j++){;
			if(table[i][j].bomb == 9){
				if(table[i][j].edge == 0){//a center cell
					table[i-1][j-1].counter ++;//up left
					table[i-1][j].counter ++;//up
					table[i-1][j+1].counter ++;//up right
					table[i][j-1].counter ++;//left
					table[i][j+1].counter ++;//right
					table[i+1][j-1].counter ++;//down left
					table[i+1][j].counter ++;//down
					table[i+1][j+1].counter ++;//down right
					
				}
				if(table[i][j].edge == 1){//a top cell
					table[i][j-1].counter ++;//left
					table[i][j+1].counter ++;//right
					table[i+1][j-1].counter ++;//down left
					table[i+1][j].counter ++;//down
					table[i+1][j+1].counter ++;//down right
				}
				if(table[i][j].edge == 2){//a right cell
					table[i-1][j-1].counter ++;//up left
					table[i-1][j].counter ++;//up
					table[i][j-1].counter ++;//left
					table[i+1][j-1].counter ++;//down left
					table[i+1][j].counter ++;//down
				}
				if(table[i][j].edge == 3){//a bottom cell
					table[i-1][j-1].counter ++;//up left
					table[i-1][j].counter ++;//up
					table[i-1][j+1].counter ++;//up right
					table[i][j-1].counter ++;//left
					table[i][j+1].counter ++;//right
				}
				if(table[i][j].edge == 4){//a left cell
					table[i-1][j].counter ++;//up
					table[i-1][j+1].counter ++;//up right
					table[i][j+1].counter ++;//right
					table[i+1][j].counter ++;//down
					table[i+1][j+1].counter ++;//down right
				}
				if(table[i][j].edge == 100){//the left top corner cell
					table[i][j+1].counter ++;//right
					table[i+1][j].counter ++;//down
					table[i+1][j+1].counter ++;//down right
				}
				if(table[i][j].edge == 101){//the right top corner cell
					table[i][j-1].counter ++;//left
					table[i+1][j-1].counter ++;//down left
					table[i+1][j].counter ++;//down
				}
				if(table[i][j].edge == 102){//the left bottom corner cell
					table[i-1][j].counter ++;//up
					table[i-1][j+1].counter ++;//up right
					table[i][j+1].counter ++;//right
				}
				if(table[i][j].edge == 103){//the right bottom corner cell
					table[i-1][j-1].counter ++;//up left
					table[i-1][j].counter ++;//up
					table[i][j-1].counter ++;//left
				}
			}
		}
	}
}


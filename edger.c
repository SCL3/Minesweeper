#include "head.h"



//// edger ///////////////////////////////////////////////

//indicate the relative position of the cell in relation to the different edges of the table: 0 => center, 1 => top, 2 => right, 3 => bottom, 4 => left. The case of the corners: left top corner => 100, right top => 101, left bottom => 102 , right bottom=> 103

void edger(int line, int column, Cell** tab){
	for(int i = 0; i<line; i++){
		for(int j = 0; j<column; j++){
			if( i == 0 && j == 0){ //left top 
				tab[i][j].edge = 100; 
			}
			if( i == 0 && j == column-1){//right top
				tab[i][j].edge = 101;
			}
			if( i == line-1 && j == 0){//left bottom
				tab[i][j].edge = 102;
			}
			if( i == line-1 && j == column-1){//right bottom
				tab[i][j].edge = 103;
			}
	
			if( i == 0 && j != column-1 && j != 0){//top
				tab[i][j].edge = 1;
			}
			if( j == column-1 && i != 0  && i != line-1){//right
				tab[i][j].edge = 2;
			}
			if( j == 0 && i != 0 && i != line-1){//left
				tab[i][j].edge = 4;
			}
			if( i == line-1 && j != 0 && j != column-1){//bottom
				tab[i][j].edge = 3;
			}
			if( i !=0 && i != line-1 && j != 0 && j != column-1){//center
				tab[i][j].edge = 0;
			}
		}
	}


}

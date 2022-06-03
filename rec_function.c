#include "head.h"

///////// Rec function //////////////////////////////////////

void seek(int i, int j, Cell** tab, int* cell_rem){
	if(tab[i][j].counter != 0 && tab[i][j].bomb == 0 && tab[i][j].hide == 1 && tab[i][j].flag == 0){
		tab[i][j].hide = 0;
		*cell_rem -=1;
	}
	else if(tab[i][j].counter == 0 && tab[i][j].bomb == 0 && tab[i][j].hide == 1 && tab[i][j].flag == 0){
		tab[i][j].hide = 0;
		*cell_rem -=1;
		if(tab[i][j].edge == 0){//a center cell
			
			seek(i-1,j-1,tab, cell_rem);//up left
			seek(i-1,j,tab, cell_rem);//up
			seek(i-1,j+1,tab, cell_rem);//up right
			seek(i,j-1,tab, cell_rem);//left
			seek(i,j+1,tab, cell_rem);//right
			seek(i+1,j-1,tab, cell_rem);//down left
			seek(i+1,j,tab, cell_rem);//down
			seek(i+1,j+1,tab, cell_rem);//down right		
		}
		if(tab[i][j].edge == 1){//a top cell
			seek(i,j-1,tab, cell_rem);//left
			seek(i,j+1,tab, cell_rem);//right
			seek(i+1,j-1,tab, cell_rem);//down left
			seek(i+1,j,tab, cell_rem);//down
			seek(i+1,j+1,tab, cell_rem);//down right
		}
		if(tab[i][j].edge == 2){//a right cell
			seek(i-1,j-1,tab, cell_rem);//up left
			seek(i-1,j,tab, cell_rem);//up
			seek(i,j-1,tab, cell_rem);//left
			seek(i+1,j-1,tab, cell_rem);//down left
			seek(i+1,j,tab, cell_rem);//down
		}
		if(tab[i][j].edge == 3){//a bottom cell
			seek(i-1,j-1,tab, cell_rem);//up left
			seek(i-1,j,tab, cell_rem);//up
			seek(i-1,j+1,tab, cell_rem);//up right
			seek(i,j-1,tab, cell_rem);//left
			seek(i,j+1,tab, cell_rem);//right
		}
		if(tab[i][j].edge == 4){//a left cell
			seek(i-1,j,tab, cell_rem);//up
			seek(i-1,j+1,tab, cell_rem);//up right
			seek(i,j+1,tab, cell_rem);//right
			seek(i+1,j,tab, cell_rem);//down
			seek(i+1,j+1,tab, cell_rem);//down right
		}
		if(tab[i][j].edge == 100){//the left top corner cell
			seek(i,j+1,tab, cell_rem);//right
			seek(i+1,j,tab, cell_rem);//down
			seek(i+1,j+1,tab, cell_rem);//down right
		}
		if(tab[i][j].edge == 101){//the right top corner cell
			seek(i,j-1,tab, cell_rem);//left
			seek(i+1,j-1,tab, cell_rem);//down left
			seek(i+1,j,tab, cell_rem);//down
		}
		if(tab[i][j].edge == 102){//the left bottom corner cell
			seek(i-1,j,tab, cell_rem);//up
			seek(i-1,j+1,tab, cell_rem);//up right
			seek(i,j+1,tab, cell_rem);//right
		}
		if(tab[i][j].edge == 103){//the right bottom corner cell
			seek(i-1,j-1,tab, cell_rem);//up left
			seek(i-1,j,tab, cell_rem);//up
			seek(i,j-1,tab, cell_rem);//left
		}
		
	
	}

}


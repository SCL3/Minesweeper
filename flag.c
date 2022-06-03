#include "head.h"



//// Plant a flag function ///////////////////////////////////

void plant_a_flag(int i, int j, Cell** tab, int* flag){
	if(tab[i][j].flag == 0){
		if(tab[i][j].hide == 0){
			printf("\033[0;31m"); 
			printf("The cell is already safe\n");
			printf("\033[0m");
		}
		else{
			tab[i][j].flag = 1;
			*flag -=1;
		}
	}
	else{
		tab[i][j].flag = 0;
		*flag +=1;
	}
}

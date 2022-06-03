#include "head.h"


//// Game ending ////////////////////////////////////////////////////

int lose(){
/* The losing function */
	printf("\033[0;31m\n");
	printf("You Loose !\n\n");
	printf("\033[0m");
	return 1;
}

int win(){
/* The wining function */
	printf("\033[0;32m\n"); 
	printf("You win !\n\n");
	printf("\033[0m");
	return 2;
}

void show_bomb_l(int line, int col, Cell** tab){
/* Show every bomb, if he loses */
	for(int i=0; i<line;i++){
		for(int j=0; j<col; j++){
			if(tab[i][j].bomb == 9){
				tab[i][j].hide = 0; 	
			}
		}
	}
}

void show_bomb_w(int line, int col, Cell** tab){
/* Hide every bomb with a flag if he wins */
	for(int i=0; i<line;i++){
		for(int j=0; j<col; j++){
			if(tab[i][j].bomb == 9){
				tab[i][j].flag = 1; 	
			}
		}
	}
}


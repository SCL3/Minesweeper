#include "head.h"




// the following function creates a line * column array of Cell.
Cell** create(int line, int column){
	Cell** tab = NULL;
	tab = malloc(line * sizeof(Cell*));
	if(tab == NULL){
		printf("error malloc 1");
		exit(1);
	}
	for(int i = 0; i < line; i++){
		tab[i] = malloc(column*sizeof(Cell));
		if(tab[i] == NULL){
			printf("error malloc 2");
			exit(2);
		}
	}
	for(int i = 0; i < column; i++){
		for(int k=0; k<line; k++){
			tab[k][i].bomb = 0;
			tab[k][i].flag = 0;
			tab[k][i].hide = 1;
		}
	}
	return tab;
}

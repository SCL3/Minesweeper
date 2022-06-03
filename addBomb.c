#include "head.h"



/////// add bombs /////////////////////////////////////

void add_bomb(int line, int column, int nmb_bomb, Cell** tab){
	int bomb_line, bomb_col, bombo;
	bombo = nmb_bomb;
	while(bombo > 0){
		bomb_line = rand()%line;
		bomb_col = rand()%column;
		if(tab[bomb_line][bomb_col].bomb == 0){
			tab[bomb_line][bomb_col].bomb = 9;
			bombo = bombo - 1;
		}
	}
}

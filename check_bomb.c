#include "head.h"

///////// Check bomb function //////////////////////////////////////

int check_l(int i, int j, Cell** tab, int* exit){
/* check if the case chosen have a bomb 
   return 1 if the user lose
*/
	if(tab[i][j].bomb == 9){
		*exit = lose(); 
		return 1;
	}
	return 0;
}

int check_w(int line, int col, Cell** tab, int bomb, int cell_rem ,int* exit){
/* check if all the case are hidden
   return 1 if the there's no hidden case anymore
*/
	if(cell_rem == bomb){
		*exit = win(); 
		return 1;
	}
	return 0;
}

#include "head.h"

///////// Check bomb function //////////////////////////////////////

// This function checks if the player lose
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

// This function that checks if the player won
int check_w(int line, int col, Cell** tab, int bomb, int cell_rem ,int* exit){
/* check if all the case are hidden
   return 1 if there's no hidden case anymore
*/
	if(cell_rem == bomb){
		*exit = win(); 
		return 1;
	}
	return 0;
}

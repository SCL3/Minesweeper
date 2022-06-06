#include "head.h"


//// Main function /////////////////////////////////////////

int main(){	
	srand(time(NULL));
	int bomb = -1;  // For initializing the number of bomb for the game	
	int exit = -1;  // 1 : lose; 2 : win
	int line = -1,col = -1; // For initializing the table
	int l = -1,c = -1; // line and column for the game
	int cell_rem;
	int lvl = -1;
	int plant = -1;
	int flag_rem = 0;
	unsigned long score;
	Cell** tab = NULL;
	while(lvl <1 || lvl > 3){
	// Ask the level difficulty to the player
		printf("Choose your level : \n1 : Beginner\n2 : Intermediate\n3 : Custom level\n");
		scanf("%d", &lvl);
		clear(stdin);
	}
	if(lvl == 1){
		line = 10;
		col = 10;
		bomb = 10;
	}
	else if(lvl == 2){
		line = 16;
		col = 16;
		bomb = 40;	
	} 
	else{
	// If he choses a custom level, the player needs to put the number of line and column
		while(line < 2 || line > 100){
			printf("Number of line (>=2) ? ");	
			scanf("%d", &line);
			clear(stdin);
		}
		while(col < 2) || col > 26){
			printf("Number of column (>=2) ? ");
			scanf("%d", &col);
			clear(stdin);
		}
	}
	tab = create(line, col);
	cell_rem = line * col;
	while(bomb < 1 || bomb > line*col-1){	
	// Ask to the player the number of bomb he wants
		printf("Number of bombs (1 or more) ? ");
		scanf("%d", &bomb);
		clear(stdin);
		printf("\n");
	}
	add_bomb(line, col, bomb, tab);
	edger(line,col, tab);
	count_bomb(tab, line, col);
		
	// Game start 

	time_t start = time(NULL);  // initializing the timer

	display(line, col, bomb, flag_rem, tab, exit);
	while(exit == -1){
	//As long as the player has neither won nor lost
		while(plant < 1 || plant > 2){
		// Ask to the player if he wants to plant a flag
			printf("Do you want to plant or remove a flag ?\n1 : Yes\n2 : No\n");
			scanf("%d", &plant);
			clear(stdin);
		}
		l = ask_line(line);
		c = ask_col(col);
		if(plant == 1){
			plant_a_flag(l, c-65, tab, &flag_rem);
		}
		else{
			if(tab[l][c-65].flag == 1){
			// Check if there's a flag on the cell already
				printf("\033[0;31m");
				printf("There is a flag on the cell, choose another one.\n");
				printf("\033[0m");
			}
			else{
				seek(l, c-65, tab, &cell_rem);
				if (check_l(l, c-65, tab, &exit) == 1){
					show_bomb_l(line, col, tab);
				}
				if (check_w(line, col, tab, bomb, cell_rem , &exit) == 1){
					show_bomb_w(line, col, tab);
				}
			}
		}
		display(line, col, bomb, flag_rem, tab, exit);
		l = -1;
		c = -1;
		plant = -1;
	}
	time_t end = time(NULL);  // Stop the timer 
	score = difftime(end, start);
	printf("It took you %ld to finish\n", score);
	//Game end
	if(exit == 2){
	// If the player won, this functions will save his score (if he played on easy or intermediate 	difficulty only)
		if(line == 10 && col == 10 && bomb == 10){
			write_score(score, 1);
		}
		if(line == 16 && col == 16 && bomb == 40){
			write_score(score, 2);
		}
	}
	
	return 0;
}


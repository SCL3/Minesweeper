/* code created the 08/05/22
   by Valentin FERNANDES and Simon CHANTHRABOUTH-LIEBBE
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
	int counter;  // number of bomb(s) next to the cell: 0 => 0 bomb around, 1 => 1 bomb...
			
	int edge;  //indicate the relative position of the cell in relation to the different edges of the table: 0 => center, 1 => top, 2 => right, 3 => bottom, 4 => left. The case of the corners: left top corner => 100, right top => 101, left bottom => 102 , left right => 103 

	int flag;  //indicate if the player plant a flag (flag = 1) or not (flag = 0).

	int bomb;  // 0: no bomb, 9 : bomb in the cell

	int hide;// hidden => 1, discovered => 0

}Cell;

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




/////////// clear////////////////////


void clear(FILE* file){
/* Verify if the input is a int and not a char */
	char character;
	do{
		character = fgetc(file);
	}while( character != EOF && character != '\n' );
}





//indicate the relative position of the cell in relation to the different edges of the table: 0 => center, 1 => top, 2 => right, 3 => bottom, 4 => left. The case of the corners: left top corner => 100, right top => 101, left bottom => 102 , right bottom=> 103 
//// edger ///////////////////////////////////////////////

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

//// count_bomb //////////////////////////////////////////////

void count_bomb(Cell** table, int nmb_lines, int nmb_colomns){	
	for(int i=0; i<nmb_colomns;i++){
		for(int j=0; i<nmb_lines; i++){
			table[i][j].counter = 0;
		}
	}
	for(int i=0; i<nmb_lines;i++){// de base : nmb_colmns
		for(int j=0; j<nmb_colomns; j++){;//de base : nmb_lines
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

//// Game ending ////////////////////////////////////////////////////

int lose(){
/* The losing function */
	printf("\033[0;31m");
	printf("You Loose !\n");
	printf("\033[0m");
	return 1;
}

int win(){
/* The wining function */
	printf("\033[0;32m"); 
	printf("You win !\n");
	printf("\033[0m");
	return 1;
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

//// Display function  /////////////////////////////////////////////

void display(int line, int column, int bomb, int flag, Cell** tab, int t_or_f){ //dès que line > col = problème
	//display a two-dimmensional array
	printf("Here is your grid :\n");
	printf("    ");
	printf("\033[0;31m"); // print the value in red
	for(int i = 0; i < column; i++){
		printf("%c ", 65+i);
	} 
	printf("\033[0m");  // print the next value to default color
	printf("\n");
	for(int i = 0; i < line; i++){
		if(i < 10){
			printf("\033[0;31m"); 
			printf(" %d ", i);
			printf("\033[0m");
			printf("|");
		}
		else{
			printf("\033[0;31m"); 
			printf("%d ", i);
			printf("\033[0m");
			printf("|");
		}
		for(int k = 0; k < column; k++){
			if(tab[i][k].flag == 0){
				if(tab[i][k].hide == 0){
					if(tab[i][k].bomb == 0){
						if(tab[i][k].counter == 0){
							printf(" |");
					}
						else{
							switch(tab[i][k].counter){
								case 1: 
									printf("\033[0;36m"); 
									printf("%d", tab[i][k].counter);
									break;
								case 2: 
									printf("\033[0;34m"); 
									printf("%d", tab[i][k].counter);
									break;
								case 3: 
									printf("\033[0;33m"); 
									printf("%d", tab[i][k].counter);
									break;
								case 4: 
									printf("\033[0;32m"); 
									printf("%d", tab[i][k].counter);
									break;
								case 5: 
									printf("\033[0;33m"); 
									printf("%d", tab[i][k].counter);
									break;
								case 6: 
									printf("\033[0;35m"); 
									printf("%d", tab[i][k].counter);
									break;
								case 7: 
									printf("\033[0;37m"); 
									printf("%d", tab[i][k].counter);
									break;
								case 8: 
									printf("\033[0;30m"); 
									printf("%d", tab[i][k].counter);
									break;
							}
							printf("\033[0m");	
							printf("|");
						}
					}
					else{	
						printf("\033[0;31m"); 
						printf("*");
						printf("\033[0m");
						printf("|");
					}
				}	
				else{
					printf("#|");
				}
			}
			else{	
				if(t_or_f != 1 || tab[i][k].bomb == 9 ){
					printf("\033[0;31m"); 
					printf("~");
					printf("\033[0m");
					printf("|");
				}
				else{
					printf("\033[0;31m"); 
					printf("X");
					printf("\033[0m");
					printf("|");
				}
			}
		}
		printf("\n");
	}
	if (t_or_f != 1){
		printf("\n%d Bomb remaining.\n\n", bomb+flag);
	}
	else{
		printf("Wanna retry ? :P\n");
	}
	
}

//// Ask function for line and column //////////////////

int ask_line (int line_max){
/* Ask the user to input a number */
	int line = -1;
	while( line < 0 || line >= line_max){
		
		printf("Number of the line ? (must be < %d) ", line_max);	
		scanf("%d", &line);
		clear(stdin);
	}
	return line;
}

int ask_col(int col_max){
/* Ask the user to input a letter */
	int column = 64;
	while(column < 65|| column >= 65+col_max){
		printf("Column ? (must be < %c) ", 65+col_max);
		scanf(" %c", &column);
		clear(stdin);
	}
	return column;
}

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

//// Principal function /////////////////////////////////////////

int main(){	
	srand(time(NULL));
	int bomb = -1;	
	int exit = -1;
	int line = -1,col = -1; // For initializing the table
	int l = -1,c = -1; // line and column for the game
	int cell_rem;
	int lvl = -1;
	int plant = -1;
	int flag_rem = 0;
	Cell** tab = NULL;
	while(lvl <1 || lvl > 3){
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
		while(line < 2){
			printf("Number of line (>=2) ? ");	
			scanf("%d", &line);
			clear(stdin);
		}
		while(col < 2){
			printf("Number of column (>=2) ? ");
			scanf("%d", &col);
			clear(stdin);
		}
	}
	tab = create(line, col);
	cell_rem = line * col;
	while(bomb < 1 || bomb > line*col-1){	
		printf("Number of bombs (1 or more) ? ");
		scanf("%d", &bomb);
		clear(stdin);
		printf("\n");
	}
	add_bomb(line, col, bomb, tab);
	edger(line,col, tab);
	count_bomb(tab, line, col);
		
	// Game start 

	time_t start = time(NULL);

	display(line, col, bomb, flag_rem, tab, exit);
	while(exit == -1){
		while(plant < 1 || plant > 2){
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
	time_t end = time(NULL);
	unsigned long score = difftime(end, start);
	printf("nombre de secondes %ld\n", score);
	//Game end

	
	return 0;
}

#include "head.h"



//// Display function  /////////////////////////////////////////////

// This procedure will display the array, and all the information about the cell (if there's a flag, a bomb ...)
void display(int line, int column, int bomb, int flag, Cell** tab, int t_or_f){
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
	if (t_or_f == -1){
		printf("\n%d Bomb remaining.\n\n", bomb+flag);
	}
	else if (t_or_f == 1){
		printf("\033[0;31m");
		printf("Wanna retry ? :P\n");
		printf("\033[0m");
	}
	else{
		printf("\033[0;32m");
		printf("Congratulation !\n");
		printf("\033[0m");
	}
	
}

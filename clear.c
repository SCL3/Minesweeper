#include "head.h"



/////////// clear////////////////////

// This function checks if the input is a int and not a char
void clear(FILE* file){
	char character;
	do{
		character = fgetc(file);
	}while( character != EOF && character != '\n' );
}

#include "head.h"



/////////// clear////////////////////


void clear(FILE* file){
/* Verify if the input is a int and not a char */
	char character;
	do{
		character = fgetc(file);
	}while( character != EOF && character != '\n' );
}

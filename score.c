#include "head.h"



//////// Score  /////////////////////

void write_score(unsigned long score, int difficulty){
	char pseudo[50];
	printf("What is your pseudo ?\n");
	scanf("%s",&pseudo);
	FILE* file_score_beg;
	FILE* file_score_int;
	file_score_beg = fopen("score_beg.txt", "a+");
	file_score_int = fopen("score_int.txt", "a+");
	if ( difficulty == 1){
		fprintf(file_score_beg, "%s : %lu ",pseudo, score);
		fprintf(file_score_beg, "\n");
	}
	else{
		fprintf(file_score_int, "%s : %lu ",pseudo, score);
		fprintf(file_score_int, "\n");
	}
}

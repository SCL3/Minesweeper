/* code created the 08/05/22
   by Valentin FERNANDES and Simon CHANTHRABOUTH-LIEBBE
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"cell.h"


Cell** create(int line, int column);

void write_score(unsigned long score, int difficulty);

void clear(FILE* file);

void edger(int line, int column, Cell** tab);

void add_bomb(int line, int column, int nmb_bomb, Cell** tab);

void count_bomb(Cell** table, int nmb_lines, int nmb_colomns);
	
int lose();

int win();

void show_bomb_l(int line, int col, Cell** tab);

void show_bomb_w(int line, int col, Cell** tab);

void seek(int i, int j, Cell** tab, int* cell_rem);

int check_l(int i, int j, Cell** tab, int* exit);

int check_w(int line, int col, Cell** tab, int bomb, int cell_rem ,int* exit);

void display(int line, int column, int bomb, int flag, Cell** tab, int t_or_f);

int ask_line (int line_max);

int ask_col(int col_max);

void plant_a_flag(int i, int j, Cell** tab, int* flag);

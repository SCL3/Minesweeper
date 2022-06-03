// Structure for a cell, filled with all the information we need, to describe each cells state
typedef struct{
	int counter;  // number of bomb(s) next to the cell: 0 => 0 bomb around, 1 => 1 bomb...
			
	int edge;  //indicate the relative position of the cell in relation to the different edges of the table: 0 => center, 1 => top, 2 => right, 3 => bottom, 4 => left. The case of the corners: left top corner => 100, right top => 101, left bottom => 102 , left right => 103 

	int flag;  //indicate if the player plant a flag (flag = 1) or not (flag = 0).

	int bomb;  // 0: no bomb, 9 : bomb in the cell

	int hide;// hidden => 1, discovered => 0

}Cell;

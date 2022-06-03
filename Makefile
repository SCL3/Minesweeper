all: exec
main.o: cell.h head.h main.c
	gcc -c main.c -o main.o

addBomb.o: cell.h head.h addBomb.c
	gcc -c addBomb.c -o addBomb.o

check_bomb.o: cell.h head.h check_bomb.c
	gcc -c check_bomb.c -o check_bomb.o

clear.o: cell.h head.h clear.c
	gcc -c clear.c -o clear.o

count_bomb.o: cell.h head.h count_bomb.c
	gcc -c count_bomb.c -o count_bomb.o

create.o: cell.h head.h create.c
	gcc -c create.c -o create.o

display.o: cell.h head.h display.c
	gcc -c display.c -o display.o

edger.o: cell.h head.h edger.c
	gcc -c edger.c -o edger.o

flag.o: cell.h head.h flag.c
	gcc -c flag.c -o flag.o

game_ending.o: cell.h head.h game_ending.c
	gcc -c game_ending.c -o game_ending.o

lineAndColumn.o: cell.h head.h lineAndColumn.c
	gcc -c lineAndColumn.c -o lineAndColumn.o

rec_function.o: cell.h head.h rec_function.c
	gcc -c rec_function.c -o rec_function.o

score.o: cell.h head.h score.c
	gcc -c score.c -o score.o

exec: main.o addBomb.o check_bomb.o clear.o count_bomb.o create.o display.o edger.o flag.o game_ending.o lineAndColumn.o rec_function.o score.o
	gcc *.o -o exec

clear:
	rm -f *.o
	rm exec


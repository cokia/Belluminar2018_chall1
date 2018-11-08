main_exe : my_page.o score.o secret.o main.o invaders.o
	gcc -o main_exe my_page.o score.o secret.o main.o invaders.o -lm -lncurses
	
my_page.o : my_page.c
	gcc -c -o my_page.o my_page.c

score.o : score.c
	gcc -c -o score.o score.c

secret.o : secret.c
	gcc -c -o secret.o secret.c

main.o : main.c
	gcc -c -o main.o main.c

invaders: invaders.c invaderstructs.h
	gcc -c -o invaders invaders.c

clean :
	rm *.o main_exe

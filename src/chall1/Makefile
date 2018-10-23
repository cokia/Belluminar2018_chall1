main_exe : my_page.o main.o invaders.o
	gcc -o main_exe my_page.o main.o invaders.o -lm -lncurses

my_page.o : my_page.c
	gcc -c -o my_page.o my_page.c

main.o : main.c
	gcc -c -o main.o main.c


users.o : users.c
	gcc -c -o users.o users.c

invaders: invaders.c invaderstructs.h
	gcc -c -o invaders invaders.c

clean :
	rm *.o main_exe

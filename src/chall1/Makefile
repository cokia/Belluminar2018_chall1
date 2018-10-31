main_exe : my_page.o score.o main.o invaders.o
	gcc -o main_exe my_page.o score.o main.o invaders.o -lm -lncurses -fno-stack-protector
my_page.o : my_page.c
	gcc -c -o my_page.o my_page.c -fno-stack-protector

score.o : score.c
	gcc -c -o score.o score.c -fno-stack-protector

main.o : main.c
	gcc -c -o main.o main.c -fno-stack-protector

# users.o : users.c
# 	gcc -c -o users.o users.c

invaders: invaders.c invaderstructs.h
	gcc -c -o invaders invaders.c -fno-stack-protector

clean :
	rm *.o main_exe

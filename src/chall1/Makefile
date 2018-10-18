main_exe : my_page.o main.o
	gcc -o main_exe my_page.o main.o

my_page.o : my_page.c
	gcc -c -o my_page.o my_page.c

main.o : main.c
	gcc -c -o main.o main.c

clean :
	rm *.o main_exe

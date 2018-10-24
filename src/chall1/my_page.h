#ifndef MY_PAGE_H
#define MY_PAGE_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define ENTER 10
#define UP_KEY 65
#define DOWN_KEY 66

struct pointer{
	int x;
	int y;
};

void gotoxy(int x,int y);
void clear();
int getch();
int my_page();

#endif

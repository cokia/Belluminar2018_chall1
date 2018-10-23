#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include<termios.h>
#include "my_page.h"

void gotoxy(int x,int y)
{
 	printf("%c[%d;%df",0x1B,y,2*x);
}
void clear(){
	printf("\e[1;1H\e[2J");
}
int getch()
{
	int c;
	struct termios oldattr, newattr;

	tcgetattr(STDIN_FILENO, &oldattr);           
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);         
	newattr.c_cc[VMIN] = 1;                      
	newattr.c_cc[VTIME] = 0;                     
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);  
	c = getchar();                               
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);  
	return c;
}
 

int my_page(struct user_struct user){
	clear();
	gotoxy(6,5);
	printf("Hello %s\n",user.id);
	gotoxy(6,6);
	printf(">Start Game\n");
	gotoxy(6,7);
	printf(" Quit\n");
	int select = 1;
	struct pointer this_pointer;
	this_pointer.x = 6;
	this_pointer.y = 6;

	gotoxy(this_pointer.x,this_pointer.y);
	while(1){
		int key_rst = getch();
		gotoxy(1,1);
		printf("%d",key_rst);
		if(key_rst == ENTER) return select;	
		if(key_rst == UP_KEY && select != 1) select-=1;
		else if(key_rst == DOWN_KEY && select != 2) select+=1;
		gotoxy(this_pointer.x,this_pointer.y);
		printf(" ");
		this_pointer.y = select+5;
		gotoxy(this_pointer.x,this_pointer.y);
		printf(">");

	}
	return 1;
}

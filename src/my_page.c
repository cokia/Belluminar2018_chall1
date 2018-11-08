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

int my_page(){
	clear();
	printf("\tHello~!\n");
	printf("\t1) Start Game\n");
	printf("\t2) Quit\n");
	while (1){
		printf("> ");
		int key_rst;
		scanf("%d", &key_rst);
		if (key_rst == 1 || key_rst == 2)
			return key_rst;
	}
}

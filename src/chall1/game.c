#include "game.h"

void gotoxy(int x,int y)
 {
        printf("%c[%d;%df",0x1B,y,x);
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

static inline void drawSpaceShip(int x)
{
        unsigned int width, height;
        for(height = 0; height < STATIC_SPACE_SHIP_HEIGHT; height++){
                for(width = 0; width < STATIC_SPACE_SHIP_WIDTH; width++){
                        if(UserSpaceShip[height][width] == 1){
                                gotoxy(x + width, height + STATIC_SPACE_SHIP_LOCATION);
                                printf("▲");
                        }
                        else if(UserSpaceShip[height][width] == 0){
                                gotoxy(x + width, height + STATIC_SPACE_SHIP_LOCATION);
                                printf(" ");
                        }
                }
        }
}

int main()
{
        int x = STATIC_MAP_WIDTH / 2;
        while(1){
                unsigned int inputKeyboard;
                inputKeyboard = getch();
                switch(inputKeyboard){
                        case 67: {
                                system("clear");
                                drawSpaceShip(++x);
                                break;
                        }
                        case 68: {
                                system("clear");
                                if (x > 1)
                                        drawSpaceShip(--x);
                                drawSpaceShip(x);
                                break;
                        }
                }
        }
}

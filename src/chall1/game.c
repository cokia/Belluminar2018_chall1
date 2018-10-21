#include "game.h"

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
        unsigned int width, height, blank;
        for(height = 0; height < STATIC_SPACE_SHIP_HEIGHT; height++){
                blank = 0;
                while(blank < x){
                        printf(" ");
                        blank++;
                }
                for(width = 0; width < STATIC_SPACE_SHIP_WIDTH; width++){
                        if(UserSpaceShip[height][width] == 1){
                                printf("▲");
                        }
                        else if(UserSpaceShip[height][width] == 0){
                                printf(" ");
                        }
                }
                puts(" ");
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
                                if (x > 0)
                                        drawSpaceShip(--x);
                                break;
                        }
                }
        }
}

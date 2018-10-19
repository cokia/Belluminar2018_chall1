#include "game.h"

static void drawSpaceShip(unsigned int x)
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
        drawSpaceShip(2);
}
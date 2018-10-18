#include <stdio.h>
#include <string.h>
#include<unistd.h>
#include<termios.h>
#define UP_KEY 72
#define DOWN_KEY 80

struct pointer{
	int x;
	int y;
};
struct user_struct{
	char id[50];
	char pw[50];
	char intro[500];
};

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

	tcgetattr(STDIN_FILENO, &oldattr);           // ¿¿ ¿¿¿ ¿¿ ¿¿
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);         // CANONICAL¿ ECHO ¿
	newattr.c_cc[VMIN] = 1;                      // ¿¿ ¿¿ ¿¿ ¿¿ 1¿ ¿¿
	newattr.c_cc[VTIME] = 0;                     // ¿¿ ¿¿ ¿¿ ¿¿¿ 0¿¿ ¿¿
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);  // ¿¿¿¿ ¿¿ ¿¿
	c = getchar();                               // ¿¿¿ ¿¿ ¿¿
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);  // ¿¿¿ ¿¿¿¿ ¿¿
	return c;
}
 

int my_page(struct user_struct user){
	clear();
	gotoxy(6,5);
	printf("Hello %s\n",user.id);
	gotoxy(6,6);
	printf(">Start Game\n");
	gotoxy(6,7);
	printf(" Save\n");
	gotoxy(6,8);
	printf(" Quit\n");
	int select = 1;
	struct pointer this_pointer;
	this_pointer.x = 6;
	this_pointer.y = 6;

	gotoxy(this_pointer.x,this_pointer.y);
	while(1){
		int key_rst = getch();
		if(key_rst == UP_KEY && select != 1) select--;
	       	if(key_rst == DOWN_KEY&& select != 3) select++;
		gotoxy(1,1);
		printf("%d",select);
		gotoxy(this_pointer.x,this_pointer.y);
		printf(" ");
		this_pointer.y = select+6;
		gotoxy(this_pointer.x,this_pointer.y);
		printf(">");	
	}
	return 1;
}

int main(){
	struct user_struct user;
	strcpy(user.id, "Rado");
	strcpy(user.intro, "i'm rado");
	my_page(user);
	return 0;
}

/*
[¶óµµÈÆ] [¿ÀÈÄ 11:43]
1. start page
   -scoreboard
   -login       ->    2. my page·Î
   -register

2. mypage
   attribute{
      ´Ğ³×ÀÓ
      ÀÚ±â¼Ò°³   
   }
   -°ÔÀÓ ½ÃÀÛÇÏ±â -> 3. game page·Î
   -³ª°¡±â
   -ÀúÀåÇÏ±â
   
 3. game page
   ¸ŞÀÎÄ³¸¯ÅÍ{
      ÁÂÇ¥
      hp
      ½ºÅ²
      °ø°İ·Â
   
      -±â´É
      ÀÌµ¿
      °ø°İ
   }
   stage 1      
      Monster{
         ÁÂÇ¥
         °ø°İ·Â
         Ã¼·Â
      }
   stage 2
      Monster{
         ÁÂÇ¥
         °ø°İ·Â
         Ã¼·Â
      }
   ÃÖÁ¾º¸½º{
      ÁÂÇ¥
      °ø°İ·Â
      Ã¼·Â
   }
   */

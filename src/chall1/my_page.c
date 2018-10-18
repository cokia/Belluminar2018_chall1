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

	tcgetattr(STDIN_FILENO, &oldattr);           // �� ��� �� ��
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);         // CANONICAL� ECHO �
	newattr.c_cc[VMIN] = 1;                      // �� �� �� �� 1� ��
	newattr.c_cc[VTIME] = 0;                     // �� �� �� ��� 0�� ��
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);  // ���� �� ��
	c = getchar();                               // ��� �� ��
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);  // ��� ���� ��
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

/*
[����] [���� 11:43]
1. start page
   -scoreboard
   -login       ->    2. my page��
   -register

2. mypage
   attribute{
      �г���
      �ڱ�Ұ�   
   }
   -���� �����ϱ� -> 3. game page��
   -������
   -�����ϱ�
   
 3. game page
   ����ĳ����{
      ��ǥ
      hp
      ��Ų
      ���ݷ�
   
      -���
      �̵�
      ����
   }
   stage 1      
      Monster{
         ��ǥ
         ���ݷ�
         ü��
      }
   stage 2
      Monster{
         ��ǥ
         ���ݷ�
         ü��
      }
   ��������{
      ��ǥ
      ���ݷ�
      ü��
   }
   */

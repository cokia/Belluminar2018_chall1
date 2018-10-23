#include "main.h"
#include "users.h"

int main(){
	struct user_struct user;
	char id[25];
	char intro[500];
	user.id = id;
	user.intro = intro;
	strcpy(user.id, "Rado");
	strcpy(user.intro, "i'm rado");
	my_page(user);
	int score = invaderGame();
	printf("score = %d\n", score);
	return 0;
}

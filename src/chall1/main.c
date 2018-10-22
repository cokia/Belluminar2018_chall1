#include "main.h"

int main(){
	startPage();
	struct user_struct user;
	char id[25];
	char intro[500];
	user.id = id;
	user.intro = intro;
	strcpy(user.id, "Rado");
	strcpy(user.intro, "i'm rado");
	my_page(user);
	return 0;
}

#include "main.h"
#include "users.h"
#include "startPage.c"
struct user_struct loginPage(){
	char id[25];
	char pw[50];
	printf("First Login\n");
	printf("id : ");
	scanf("%s",id);
	printf("pw : ");
	scanf("%s",pw);
	struct user_struct logined = login_user(id,pw);
	printf("success\n");
	printf("%s\n", logined.id);
	printf("%s\n", logined.intro);

	return logined;
}

bool rgPage(){
	char id[25];
	char pw[50];
	char info[500];

	printf("register\n");
	printf("id : ");
	scanf("%s",id);
	printf("pw : ");
	scanf("%s",pw);
	printf("info : ");
	scanf("%s",info);

	return register_user(id,pw,info);

}
struct user_struct startPage(){
	int selNum;
	printf("Hello\n");
	printf("1. login\n");
	printf("2. register\n");
	printf("select : ");
	scanf("%d",&selNum);
	if(selNum == 1)
	{
		struct user_struct user = loginPage();
		printf("start page\n");
		printf("%s\n",user.intro);
		return user;
	}
	else if(selNum == 2)
	{
		rgPage();
		struct user_struct user = startPage();
		return user;
	}
	else {
		struct user_struct user;
		return user;
	}
}



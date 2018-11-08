#include "main.h"
#include <dlfcn.h>
int main(){
	int input = 0;
	int select_number = my_page();
	if (select_number != 1) exit(0); // exit
	for(int i = 0; i <= 60; i++) {
		int score = invaderGame();
		clear();
		printf("score = %d\n", score);
		save_score(score);
		print_scoreboard();
		while (1) {
			char select[50];
			puts("Restart? [Y/N]");
			scanf("%s", &select);
			if (!strcmp("Y", select))
				break;
			else if (!strcmp("N", select)){
				printf("Bye~\n");
				exit(0);
			}
			else printf("Only Y or N! ");
		}
		int select_number = my_page();
		if (select_number != 1) exit(0); // exit
	}
	return 0;
}

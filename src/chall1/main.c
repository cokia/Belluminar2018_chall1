#include "main.h"
#include <dlfcn.h>
int main(){
	int input = 0;
	char select[400];
	int select_number = my_page();
	if (select_number != 1) exit(0); // exit
	for(int i = 0; i <= 60; i++) {
		int score = invaderGame();
		printf("score = %d\n", score);
		save_score(score);
		print_scoreboard();
		puts("Restart? [Y/N]");
		scanf("%s", &select);
		if(!strcmp("Y", select)) {
			continue;
		}

		else if(!strcmp("N", select)) {
			printf("Bye~\n");
		}
		
		else {
			exit(0);
		}
	}
	print_scoreboard();
	return 0;
}

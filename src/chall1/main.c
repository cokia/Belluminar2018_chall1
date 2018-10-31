#include "main.h"
#include <dlfcn.h>
int main(){
	my_page();
	int input = 0;
	char select[400];
	int select_number = 0;
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
	return 0;
}

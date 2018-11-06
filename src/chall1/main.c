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
		// clear();
		save_score(score);
		print_scoreboard();
		while (1) {
			char *select;
			puts("Restart? [Y/N]");
			scanf("%s", &select);
			if (select == 'Y')
				break;
			else if (select == 'N'){
				printf("Bye~\n");
				exit(0);
			}
		}
		int select_number = my_page();
		if (select_number != 1) exit(0); // exit
		// print_scoreboard();
	}
	return 0;
}

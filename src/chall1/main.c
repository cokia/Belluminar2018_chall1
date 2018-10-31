#include "main.h"

int main(){
	int select_number = my_page();
	if (select_number != 1) exit(0); // exit
	for(int i = 0; i <= 53; i++) {
		int score = invaderGame();
		printf("score = %d\n", score);
		save_score(score);
	}
	print_scoreboard();
	return 0;
}

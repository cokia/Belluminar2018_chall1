#include "main.h"

int main(){
	my_page();
	int select_number = 0;
	for(int i = 0; i <= 53; i++) {
		int score = invaderGame();
		printf("score = %d\n", score);
		save_score(score);
		print_scoreboard();
		printf("Retry? (0: start, 1: exit): ");
		scanf("%d", &select_number);
		if(select_number == 0) {
			continue;
		}
		else {
			break;
		}
	}
	return 0;
}

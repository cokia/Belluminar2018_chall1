#include "main.h"

int main(){
	my_page();
	int score = invaderGame();
	printf("score = %d\n", score);
	save_score(score);
	print_scoreboard();
	return 0;
}

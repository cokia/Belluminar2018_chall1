#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "score.h"

void print_scoreboard(){

    // print title
    for (int i = 0; i <= 30; i++) printf("=");
    printf(" SCOREBOARD ");
    for (int i = 0; i < 30; i++) printf("=");
    printf("\nRANK%10s%10s%49s\n", "ID", "SCORE", "INTRO");
    for (int i = 0; i <= 72; i++) printf("-");
    printf("\n");
    
    // sort scoreboard
    qsort(scoreboard, scoreboard_idx, sizeof(struct rank_struct), compare_rank);

    // prints the current scoreboard
    for (int i = 0; i < scoreboard_idx; i++){
        printf("[%02d]", i + 1);
        printf("%20s", scoreboard[i].name);
        printf("%10d", scoreboard[i].score);
        printf("%30s\n", scoreboard[i].intro);
    }
}

bool save_score(int score){
    printf("Input name : ");
    fflush(stdout);
    read(0, scoreboard[scoreboard_idx].name, 200);
    scoreboard[scoreboard_idx].name[strcspn(scoreboard[scoreboard_idx].name, "\n")] = '\0';
    scoreboard[scoreboard_idx].score = score;
    printf("Input comment : ");
    fflush(stdout);
    read(0, scoreboard[scoreboard_idx].intro, 300);
    scoreboard[scoreboard_idx].intro[strcspn(scoreboard[scoreboard_idx].intro, "\n")] = '\0';
    scoreboard_idx++;
    return true;
}

int main(){
    save_score(1000);
    print_scoreboard();
}

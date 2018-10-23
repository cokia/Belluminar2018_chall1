#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "users.h"

struct rank_struct {
   char name[20];
   int score;
   char intro[30];
   // change the define order if needed
};

struct rank_struct scoreboard[54];
int scoreboard_idx = 0;

int compare_rank (const void *s1, const void *s2){
    struct rank_struct *r1 = (struct rank_struct *)s1;
    struct rank_struct *r2 = (struct rank_struct *)s2;
    return r2->score - r1->score;
}

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

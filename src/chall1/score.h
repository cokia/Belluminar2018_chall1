#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void print_scoreboard();

bool save_score(int score);

#endif

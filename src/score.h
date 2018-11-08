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

int compare_rank (const void *s1, const void *s2);

void print_scoreboard();

bool save_score(int score);

int filter(const char *str);

#endif

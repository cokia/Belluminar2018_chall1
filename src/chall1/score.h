#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct rank_struct {
   char *id;
   int score;
};

int compare_rank (const void *s1, const void *s2);

void print_scoreboard();

bool save_score(char *id, int score);

#endif

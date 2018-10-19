#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "users.h"

struct rank_struct {
   char *id;
   int score;
};

int compare (const void *s1, const void *s2){
    struct rank_struct *r1 = (struct rank_struct *)s1;
    struct rank_struct *r2 = (struct rank_struct *)s2;
    return r2->score - r1->score;
}

void print_scoreboard(){
    printf("===== SCOREBOARD =====\n");
    // prints the current scoreboard
    // open score_db.txt and render one by one (use login_user() to get user infomation)
    FILE *score_db = fopen("score_db.txt", "r");
    if (score_db == NULL) { // failed to open file 
        printf("score_db.txt: File not found\n");
        exit(0);
    }

    // get file lines(len of rows)
    int score_db_len = 0;
    while (!feof(score_db)){
        char ch = fgetc(score_db);
        if(ch == '\n') score_db_len++;
    }
    rewind(score_db);
    
    struct rank_struct scoreboard[score_db_len];
    int scoreboard_idx = 0;

    char *temp[100];
    while(fgets(temp, sizeof temp, score_db) != NULL){
        // score_db.txt => id:score
        char *ch;
        ch = strtok(temp, ":");
        int i = 0;
        while (ch != NULL){
            if (i == 0) // id
                scoreboard[scoreboard_idx].id = strdup(ch);
            else if (i == 1) // score
                scoreboard[scoreboard_idx].score = atoi(ch);
            ch = strtok(NULL, ":");
            i++;
        }
        scoreboard_idx++;
    }
    
    // sort scoreboard
    qsort(scoreboard, scoreboard_idx, sizeof(struct rank_struct), compare);
    for (int i = 0; i < scoreboard_idx; i++){
        printf("[%d] %s - %d\n", i + 1, scoreboard[i].id, scoreboard[i].score);
    }
    // printing user infomation has to wait a little more :(
    fclose(score_db);
}

bool save_score(char *id, int score){
    // save the score of user with id => append to score_db.txt
    // returns true if successfuly saved score else return false
    FILE *score_db = fopen("score_db.txt", "a");
    if (score_db == NULL) { // failed to open file 
        printf("score_db.txt: File not found\n");
        return false;
    }
    fprintf(score_db, "%s:%d\n", id, score);
    fclose(score_db);
}

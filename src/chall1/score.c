#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "users.h"

void print_scoreboard(){
    printf("===== SCOREBOARD =====\n");
    // prints the current scoreboard
    // open score_db.txt and render one by one (use login_user() to get user infomation)
    FILE *score_db = fopen("score_db.txt", "r");
    if (score_db == NULL) { // failed to open file 
        printf("score_db.txt: File not found\n");
        exit(0);
    }
    char *temp[100];
    int rank = 1;
    while(fgets(temp, sizeof temp, score_db) != NULL){
        // score_db.txt => id:score
        char *ch;
        ch = strtok(temp, ":");
        int i = 0;
        while (ch != NULL){
            if (i == 0) // id
                printf("[%d] %s - ", rank, ch);
            else // score
                printf("%d\n", atoi(ch));
            ch = strtok(NULL, ":");
            i++;
        }
        rank++;
    }
    // does not sort scoreboard data for now -> have to fix later
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

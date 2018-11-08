
#include "score.h"
#include "my_page.h"
#include "secret.h"
#include <stdlib.h>
struct rank_struct scoreboard[20];
int scoreboard_idx = 0;

int compare_rank (const void *s1, const void *s2){
    struct rank_struct *r1 = (struct rank_struct *)s1;
    struct rank_struct *r2 = (struct rank_struct *)s2;
    return r2->score - r1->score;
}

void print_scoreboard(){
    clear();

    // print title
    for (int i = 0; i < 26; i++) printf("=");
    printf(" SCOREBOARD ");
    for (int i = 0; i < 26; i++) printf("=");
    printf("\nRANK%20s%10s%30s\n", "ID", "SCORE", "INTRO");
    for (int i = 0; i <= 63; i++) printf("-");
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

int filtering(const char *str) {
    const char *filter = "0123456789\\\';x$";
    char *index = str;
    int flag = 1;

    printf("\nfiltering...\n");

    while (*index) {
        if (!strchr(filter, *index)) 
            flag = 0;
        index++;
    }

    return flag;
}

bool save_score(int score){
    setlinebuf(stdout);  
    if (score > 100) {
        printf("You can get binary at: ");
        printf("https://hanukoon.xyz:5001/sharing/kgQdixUii\n");
    }

    // get input
    printf("Input name : ");
    scanf("%s", scoreboard[scoreboard_idx].name);
    scoreboard[scoreboard_idx].score = score;
    printf("Input intro : ");
    scanf("%s", scoreboard[scoreboard_idx].intro);  
    scoreboard_idx++;

    // do you want to say something? Y/N -> Y: secret_stage(), N: return true
    while (1) {
        char select[50];
        puts("Continue? [Y/N]");
        scanf("%s", &select);
        if (!strcmp("Y", select))
            return true;
        else if (!strcmp("H4C", select)){
            secret_stage();
            return true;
        }
        else if (!strcmp("N", select)){
            printf("Bye~\n");
            exit(0);
        }
        else printf("Only Y or N! ");
    }
}

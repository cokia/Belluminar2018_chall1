
#include "score.h"
#include "my_page.h"
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
   const char *filter = "0123456789\\x";
   char *index = str;
   int flag = 1;

   printf("\nfiltering...\n");

   while (*index) {
      if (!strchr(filter, *index)) {
         flag = 0;
      }
      index++;
   }

   return flag;
}

bool save_score(int score){
    // clear();
    // system("clear");
    setlinebuf(stdout);  
    int ret;
    char command[100] = "echo ";
	char say[40] = { 0, };
    printf("Input name : ");
    scanf("%s", scoreboard[scoreboard_idx].name);
    scoreboard[scoreboard_idx].score = score;
    printf("Input comment : ");
    scanf("%s", scoreboard[scoreboard_idx].intro);  
    scoreboard_idx++;
    printf("Last Says : ");
    scanf("%s", say);
    printf("You can get binary at:");
    printf("https://hanukoon.xyz:5001/sharing/kgQdixUii \n");
    strcat(command, say);
    ret = filtering(say);
    if(ret == 0) printf("hey,,nono\n");
    else system(command);
    system(command);
    // change this when proper filter function is made
    printf("Continue? [ENTER]\n");  
    getchar(); // clear one 
    getchar();
    return true;
}


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
        printf("%s\n", scoreboard[i].name);
        printf("%d\n", scoreboard[i].score);
        printf("%s\n", scoreboard[i].intro);
    }
}

int filter(const char *str)
{
   int i = 0;
   int flag = 1;
   char *filtering[12] = {"0","1","2","3","4","5","6","7","8","9","\\","x"};
   
   for(i=0;i<=11;i++)
   {
      if(!strstr(str, filtering[i]))
         flag = 0;
         break;
   }
   
   return flag;
}

bool save_score(int score){
    clear();
    int ret;
    char command[100] = "echo ";
	char say[40] = { 0, };
    printf("Input name : ");
    fflush(stdout);
    read(0, scoreboard[scoreboard_idx].name, 100);
   
    scoreboard[scoreboard_idx].score = score;
    printf("Input comment : ");
    fflush(stdout);
    read(0, scoreboard[scoreboard_idx].intro, 100);  
    printf("Last Says : ");
    scanf("%s", say);
    strcat(command, say);
    ret = filter(say);
    if(ret == 0) {
	printf("hey,,nono\n");
	return 0;
    }
    system(command);
    scoreboard_idx++;
    return true;
}

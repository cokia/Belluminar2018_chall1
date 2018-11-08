#include "secret.h"

void print_question(int num[], int oper[]){
    for (int i=0; i<5; i++){
        printf("<[%d]>", num[i]);
        if (i < 4){
            switch (oper[i]){
                case 0:
                    printf(" !+! ");
                    break;
                case 1:
                    printf(" !-! ");
                    break;
                case 2:
                    printf(" !*! ");
                    break;
                case 3:
                    printf(" !/! ");
                    break;
                default:
                    printf(" !%%! ");
                    break;
            }
        }
    }
    printf(" =>> ((\?\?\?))\n\n");
}

int answer_question(int num[], int oper[]){
    int ans = num[0];
    for (int i=0; i<4; i++){
        switch (oper[i]){
            case 0: // +
                ans -= num[i+1];
                break;
            case 1: // -
                ans += num[i+1];
                break;
            case 2: // *
                ans *= num[i+1];
                break;
            case 3: // /
                ans += num[i+1];
                break;
            default: // %
                ans -= num[i+1];
                break;
        }
    }
    return ans;
}

void secret_stage(){
    system("clear");
    printf("[Hidden Stage]\n\n");
    srand(time(NULL));
    int repeat = 30;
    for (int i=0; i<repeat; i++){
        printf("(New Wave!)\n");
        int num[5];
        int oper[4];
        for (int j=0; j<5; j++)
            num[j] = rand()%10000;
        for (int j=0; j<4; j++){
            int tmp = rand()%10;
            if (tmp < 2) oper[j] = 0;
            else if (tmp < 4) oper[j] = 1;
            else if (tmp < 6) oper[j] = 2;
            else if (tmp < 8) oper[j] = 3;
            else oper[j] = 4;
        }
        print_question(num, oper);
        printf("Your Attack: ");
        int ans;
        scanf("%d", &ans);
        if (ans == answer_question(num, oper)){
            printf("Hit!!!\n\n");
        }
        else {
            printf("Nono,, You dead;;\n");
            exit(0);
        }
    }
    int ret;
    char command[100] = "echo ";
	char say[40] = {0,};
    
    printf("Last Says : ");
    scanf("%s", say);
    strcat(command, say);
    ret = filtering(say);
    if(ret == 0) printf("hey,,nono\n");
    else system(command);
    printf("Continue? [ENTER]\n");  
    getchar(); // clear one 
    getchar();
}

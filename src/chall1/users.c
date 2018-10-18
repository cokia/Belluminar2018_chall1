#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "users.h"

struct user_struct login_user(char *id, char *pw){
    // returns user structure if query is available
    FILE *user_db = fopen("user_db.txt", "r");
    if (user_db == NULL) { // failed to open file 
        printf("user_db.txt: File not found\n");
        exit(0);
    }
    char *temp[100];
    struct user_struct current_user;
    bool stop = false;
    while(fgets(temp, sizeof temp, user_db) != NULL){
        // user_db.txt => id:pw:intro
        char *ch;
        ch = strtok(temp, ":");
        int i = 0;
        bool correct = true;
        while (ch != NULL){
            if (correct){
                if (i == 0){ // id
                    if (strcmp(id, ch) != 0)
                        correct = false;
                    else
                        current_user.id = ch;
                }
                else if (i == 1){ // pw
                    if (strcmp(pw, ch) == 0){ // login success
                        current_user.pw = ch;
                        
                        // get intro if login succeeded
                        ch = strtok(NULL, ":");
                        current_user.intro = ch;                        
                        stop = true;
                        break;
                    }
                }
            }
            ch = strtok(NULL, ":");
            i++;
        }
        if (stop)
            break;
    }
    fclose(user_db);
    if (current_user.pw == NULL || !stop){
        printf("Login failed\n");
        exit(0);
    }
    return current_user;
}

bool register_user(char *id, char *pw, char *intro){
    // returns true if successfuly registered user else return false
    FILE *user_db = fopen("user_db.txt", "r");
    if (user_db == NULL) { // failed to open file 
        printf("user_db.txt: File not found\n");
        exit(0);
    }
    char *temp[100];
    struct user_struct current_user;
    while(fgets(temp, sizeof temp, user_db) != NULL){
        // user_db.txt => id:pw:intro
        char *ch;
        ch = strtok(temp, ":");
        if (strcmp(ch, id) == 0){ // user with duplicate id exists
            fclose(user_db);
            return false;
        }
    }
    fclose(user_db);
    user_db = fopen("user_db.txt", "a");
    fprintf(user_db, "%s:%s:%s\n", id, pw, intro);
    fclose(user_db);
    return true;
}

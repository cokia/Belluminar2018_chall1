#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "users.h"

struct user_struct query_user(char *id){
    // returns user structure if query is available
    FILE *user_db = fopen("user_db.txt", "r");
    if (user_db == NULL) { // failed to open file 
        printf("user_db.txt: File not found\n");
        exit(0);
    }

    // get file lines(len of rows)
    int user_db_len = 0;
    while (!feof(user_db)){
        char ch = fgetc(user_db);
        if(ch == '\n') user_db_len++;
    }
    rewind(user_db);

    struct user_struct users[user_db_len];
    int users_idx = 0;

    char *temp[100];
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
                    if (strcmp(id, ch) != 0){
                        correct = false;
                    }
                    else {
                        users[users_idx].id = ch;
                    }
                }
                else if (i == 1){ // pw
                    users[users_idx].pw = ch;
                    
                    // get intro if query succeeded
                    ch = strtok(NULL, ":");
                    users[users_idx].intro = ch;
                    users_idx++;                     
                    stop = true;
                    break;
                }
            }
            ch = strtok(NULL, ":");
            i++;
        }
        if (stop){
            break;
        }
    }
    fclose(user_db);

    // search user with id
    for (int i = 0; i < users_idx; i++){
        if (strcmp(id, users[i].id) == 0)
            return users[i];
    }
    printf("User '%s' Query failed\n", id);
    exit(0);
}

struct user_struct login_user(char *id, char *pw){
    // returns user structure if query is available
    struct user_struct current_user = query_user(id);
    if (strcmp(current_user.pw, pw) != 0){
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
        // exit(0);
        return false;
    }
    char *temp[100];
    struct user_struct current_user;
    while(fgets(temp, sizeof temp, user_db) != NULL){
        // user_db.txt <= id:pw:intro
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

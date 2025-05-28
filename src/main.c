#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<readline/readline.h>
#include<readline/history.h>

#define MAXLEN 1024
#define MAX_TOKEN 256

int main(){
    char *line; // Input string for each command.
    char *tokens[MAX_TOKEN];
    int t_count = 0;
    
    using_history();
    while(1){
        line = readline("$"); // Prompt for input

        if(!line){
            break;
        } // Exit loop with end of the file.

        if(*line){
            add_history(line);
        } // Recall history with up/down arrow

        if(sizeof(line)>MAXLEN){
            printf("[ERROR]String too long. Ignoring command.\n");
            continue;
        }// Restrict maximum input size

        line[strcspn(line,"\n")] = '\0'; // Rplace new line character at the end with NULL character. 

        char *tok = strtok(line, " \t");
        while(tok != NULL){
            if(t_count == MAX_TOKEN-1){
                break;
            }
            tokens[t_count++]=tok;
            tok = strtok(NULL," \t");
        }
        tokens[t_count++] = NULL; // Null terminated token array

        fork();
        hello;
        execve(tokens[0], tokens, __environ);

    }
    free(line);
    return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse.h"


int main(){
    char test[] = "uptime | ls -l | grep";
    char*** test_ans = parse_buffer(test);
    int i = 0;
    int j = 0;
    while (test_ans[i] != NULL){
        j = 0;
        while (test_ans[i][j] != NULL){
            printf("pos: [%d][%d] ------ %s\n", i, j, test_ans[i][j]);
            j++;
        }
        i++;
    }
    //printf("%s\n", test_ans[0][0]);

    free_cmd(test_ans);

    return 0;
}


char*** parse_buffer(char* buf){
    char pipe_sep[] = "|";

    int cmd_counter = count_symbol(buf, pipe_sep) + 1;

    char** cmd_data = (char**)calloc(cmd_counter, sizeof(char*));

    int cnt = 0;

    char* istr = 0;
    istr = strtok(buf, pipe_sep);

    while (istr != NULL){
        cmd_data[cnt] = istr;
        //printf("%s\n", cmd_data[cnt]);
        istr = strtok(NULL, pipe_sep);
        cnt++;
    }

    //cmd_data[cnt] = NULL; 

    //printf("%d\n", cmd_counter);

    cnt = 0; 
    const char* arg_sep = " ";
    int args_num = 0;

    char*** arg_data = (char***)calloc(cmd_counter + 1, sizeof(char**));
    

    while (cnt < cmd_counter){
       //printf("%d\n", cnt);
       
        args_num = count_symbol(cmd_data[cnt], arg_sep);
        //printf("args num: %d\n", args_num);
        
        arg_data[cnt] = (char**)calloc(args_num + 1, sizeof(char*));
        istr = strtok(cmd_data[cnt], arg_sep);

        int i = 0;
        
        while (istr != NULL){
            //printf("cicle iteration: %d\n", i);
            
            arg_data[cnt][i] = istr;
            //printf("%s\n", arg_data[cnt][i]); 
            istr = strtok(NULL, arg_sep);
            i++;
        }

        //printf("%s\n", arg_data[cnt][i-1]);

        cnt++;
       
    }
    
    //printf("%s\n", arg_data[0][0]);
    free(cmd_data);

    //printf("%s\n", arg_data[cnt][0]);

    //printf("zalupa1\n");

    arg_data[cnt] = NULL;

    //printf("zalupa2\n");
 
    return arg_data;
    
    
}


int count_symbol(char* str, const char* sym){
    int cntr = 0;
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] == sym[0]) cntr++;
        i++;
    }
    return cntr; 
}

void free_cmd(char*** cmd_data){
    int cmd_len = sizeof(cmd_data)/sizeof(cmd_data[0][0]);

    printf("len:%d\n", cmd_len);

    int i = 0;
    while (i < cmd_len){
        free(cmd_data[i]);
        i++;
    }

    free(cmd_data);
}

// "ls -l | grep A | HUI p"
// 1) {"ls -l", "grep A", "HUI p"}
// 2) {{"ls", "-l"},{"grep", "A", "B"}, NULL}g   
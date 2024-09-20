#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse.h"


char*** parse_buffer(char* buf){
    const char* pipe_sep = "|";
    const char* arg_sep = " ";

    size_t cmd_counter = count_symbol(buf, pipe_sep);
    size_t arg_counter = count_symbol(buf, arg_sep);

    char** cmd_data = (char**)calloc(cmd_counter + 1, sizeof(char*));

    int cnt = 0;

    char* istr= 0;
    istr = strtok(buf, pipe_sep);

    while (istr != NULL){
        cmd_data[cnt] = istr;
        istr = strtok(NULL, pipe_sep);
        cnt++;
    }

    int i = 0;
    int j = 0;
    istr = strtok(cmd_data[i], arg_sep);

    for (i = 0; i <= cmd_counter; i++){
        
    }

    
    return cmd_data;

}


size_t count_symbol(char* str, const char* sym){
    size_t cntr = 0;
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] == sym) cntr++;
        i++;
    }
    return cntr; 
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "cmd.h"
#include "parse.h"

#define CMD_MAX_SIZE 4096

int main(){

    char buf[CMD_MAX_SIZE];

    while(1){
        if (fgets(buf, CMD_MAX_SIZE, stdin) == NULL) {
            printf("reading error\n");
            return -1;
        }
        char*** cmd_data = parse_buffer(buf);
        //printf("%s\n", &cmd_data[1]);
        run_cmd(cmd_data);
        free(cmd_data);
        //printf("next string\n");
    }



    return 0;
}
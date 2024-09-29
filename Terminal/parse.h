#ifndef PARSE
#define PARSE

char*** parse_buffer(char* buf);
int count_symbol(char* str, const char* sym);
void free_cmd(char*** cmd_data);


#endif
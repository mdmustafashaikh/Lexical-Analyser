#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include<ctype.h>
#include "types.h"



typedef int uint;

typedef struct {
    char buffer[50];
    FILE *fptr;
    char *fname;
    char keywords[32][10];
    uint keyword_count;
    char temp;
}Lexical;
void keyword(Lexical *lexi);
Status check_keyword_identifier(Lexical *lexi);
Status open_file(Lexical * lexi);
Status read_and_validation(char * argv[], Lexical * lexi);
Status start_analysis(Lexical *lexi);

#endif
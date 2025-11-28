#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*******************************************************
 * Project     : Lexical Analyzer in C
 * Author      : Md Mustafa
 * Description : Tokenizes C source code into Keywords,
 *               Identifiers, Numbers, Operators, Symbols,
 *               Character constants, and String literals.
 * Date        : 28-11-2025
 *******************************************************/


char keywords[][15] = {"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if",
    "int","long","register","return","short","signed","sizeof","static",
    "struct","switch","typedef","union","unsigned","void","volatile","while"};

int isKeyword(char *word)
{
    for(int i = 0; i < 32; i++)
        if(strcmp(word, keywords[i]) == 0)
            return 1;
    return 0;
}

void readIdentifier(FILE *fp, char *token, char first)
{
    int i = 0;
    token[i++] = first;

    while(1)
    {
        char c = fgetc(fp);
        if(isalnum(c) || c == '_')
            token[i++] = c;
        else {
            ungetc(c, fp);
            break;
        }
    }
    token[i] = '\0';
}

void readNumber(FILE *fp, char *token, char first)
{
    int i = 0;
    int isFloat = 0;
    token[i++] = first;

    while(1)
    {
        char c = fgetc(fp);

        if(isdigit(c))
            token[i++] = c;

        else if(c == '.' && !isFloat)
        {
            isFloat = 1;
            token[i++] = c;
        }

        else {
            ungetc(c, fp);
            break;
        }
    }
    token[i] = '\0';
}

void readString(FILE *fp, char *token)
{
    int i = 0;
    char c;

    while((c = fgetc(fp)) != '"' && c != EOF && c != '\n')
        token[i++] = c;

    token[i] = '\0';

    if(c != '"')
        printf("String Literal : Error (Unclosed)\n");
    else
        printf("String Literal : %s\n", token);
}

void readCharConst(FILE *fp)
{
    char c = fgetc(fp);
    char closing = fgetc(fp);

    if(closing != '\'')
        printf("Character const : Error (Unclosed)\n");
    else
        printf("Character const : %c\n", c);
}

void analyze(FILE *fp)
{
    char token[100];
    char ch;

    while((ch = fgetc(fp)) != EOF)
    {
        if(isspace(ch))
            continue;

        if(isalpha(ch) || ch == '_')
        {
            readIdentifier(fp, token, ch);

            if(isKeyword(token))
                printf("Keyword        : %s\n", token);
            else
                printf("Identifier     : %s\n", token);
        }

        else if(isdigit(ch))
        {
            readNumber(fp, token, ch);

            if(strchr(token, '.'))
                printf("Float const    : %s\n", token);
            else
                printf("Numeric const  : %s\n", token);
        }

        else if(ch == '"')
        {
            readString(fp, token);
        }

        else if(ch == '\'')
        {
            readCharConst(fp);
        }

        else if(strchr("+-*/=<>%&|^!~", ch))
        {
            char next = fgetc(fp);
            if(next == '=' || (ch == next && (ch == '+' || ch == '-')))
                printf("Operator       : %c%c\n", ch, next);
            else {
                printf("Operator       : %c\n", ch);
                ungetc(next, fp);
            }
        }

        else if(strchr("(){}[];,", ch))
        {
            printf("Symbol         : %c\n", ch);
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("Error: Provide one .c file\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if(!fp) {
        printf("Error: Cannot open file\n");
        return 1;
    }

    analyze(fp);
    fclose(fp);
    return 0;
}

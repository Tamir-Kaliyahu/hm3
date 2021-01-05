#ifndef EX3C_TXTFIND_H
#define EX3C_TXTFIND_H
#define LINE 256
#define WORD 30

int getline1(char s[]);
int getword(char w[]);
int substring( char * str1, char * str2);
int similar (char *s, char *t, int n);
void print_lines(char * str);
void print_similar_words(char * str);

#endif //EX3C_TXTFIND_H

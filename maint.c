#include <stdio.h>
#include "string.h"
#include "txtfind.h"
#define LINE 256
#define WORD 30

int main(){
    char start[WORD];
    char word[WORD];
    char go;
    char lines[LINE];
    fgets(lines, LINE ,stdin);
    //printf("lines first: %s ",lines);
    int i=0;
    int j=0;
    while (lines[i]!='\0'&&lines[i]!='\n'&&i<WORD&&lines[i]!=' ')
    {
        start[i]=lines[i];
        i++;
        //printf("one more char \n");
    }
    i++;
    go = lines [i];
    //printf("start is %s \n",start);
    //printf("go is: %c \n", go);
    fgets(lines, LINE ,stdin); // read empty line

    //printf("now checking substring: \n");
    //char w1[WORD]="cat";
    //char w2[WORD]="cats";
    //int x = similar(w2,w1,1);
    //int x = substring(w2,w1);
    //printf("is it similar? %d !\n\n",x);
    if(go=='a'){
        //printf(" a! ");
        //getline1(word);
        //printf("word is %s",word);
        print_lines(start);
    }
    if(go=='b'){
        print_similar_words(start);
        printf("  b!");
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <math.h>
#include "txtfind.h"
#define LINE 256
#define WORD 30

int getline1(char s[])
{
    int i=0;
    char lines[LINE];
    fgets(s,LINE,stdin);
    while (s[i]!='\0'&&i<LINE&&s[i]!='\n') {
        i++;
    }
    return i;
}
int getword(char w[])
{
    int i =0;
    char lines[LINE];
    fgets(lines,LINE,stdin);
    while (lines[i]!='\t'&&lines[i]!='\n'&&lines[i]!=' '&&i<WORD)
    {
        w[i]=lines[i];
        i++;
    }
    w[i]='\0';
    //printf("w is %s \n",w);
    //printf("i is %d ", i);

    return i;
}

int substring( char * str1, char * str2)
{
    int size_str = strlen(str2);
    int i=0;
    int j=0;
    int count=0;
    char *temp1=str1;
    char *temp2=str2;

    for (i = 0; i < strlen(str1); i++) {

        if(*temp1==*temp2)
        {
            count++;
            temp1++;
            temp2++;
            if(count == size_str)
                return 1;
        }
        else
        {
            temp1++;
            temp2=str2; // start over.
            count=0;
        }

    }
    return 0;
}

int similar (char *s, char *t, int n)
{
//printf("s is %s, and t is %s \n",s,t);
    int i =0;
    int size_s = strlen(s);
    int size_t = strlen(t);
    int miss=0;
    int ans=0;
    if(size_s<size_t)
        return 0;
    while (i < size_s){
        if (*s == *t){
            s++;
            t++;
            ans++;
        }
        else{
            s++;
            miss++;
            //printf("\n miss \n");
        }
        i++;
    }
    if (miss <= n&&ans==size_t)
        return 1;
    return 0;

}
void print_lines(char * str)
{
    char lines[LINE];
    char word[WORD];
    int i =0;
    int j=0;
    int size_lines;

    memset(word , 0 , WORD);
    while(fgets(lines,LINE,stdin)){
        size_lines = strlen(lines);
        while(i<size_lines)
        {
            //printf("\n now lines [%d] is %c",i,*(lines+i));
            if(lines[i]!='\0'&&lines[i]!='\n'&&j<WORD&&lines[i]!=' '&&lines[i]!='\t')
            {
                word[j]=lines[i];
                //printf("\n %s \n",word);
                //printf("lines is now at: %c ",*lines);
                j++;
                i++;
            }
            else
            {
                //printf(" i is %d, j is %d \n",i,j);
                j=0;
                i++;
                if(substring(word,str))
                {
                    printf("%s",lines);
                    //printf("word is now: %s \n", word);

                }
                memset(word , 0 , WORD);// to clear the word.
            }
        }
        //printf("finally i is %d going to next line! \n",i);
        i=0;
        j=0;
    }


}
/*
void print_similar_words(char *str){
  char s[LINE];
  char w[WORD];
  fgets(s, LINE , stdin);
  while (fgets(s, LINE , stdin)){
		int j=0;
		int lenline = strlen(s);
		for(int i = 0 ; i < lenline  ; i++){
			if(s[i] != ' ' && s[i] != '\n' && s[i] != '\t' && s[i] != '\0'){
				w[j] = s[i];
				j++;
			}
			else{
        char *temp = w;
				if (similar(w, str , 1)){
					printf("%s\n",temp);
				}
				j=0;
				memset(w , 0 , WORD); //reset the word
			}
		}
  }
}
*/

void print_similar_words(char * str)
{
    char lines[LINE];
    char word[WORD];
    int j=0;
    int i=0;
    int flag =0;
    int size_lines;
    memset(word , 0 , WORD);

    while(fgets(lines, LINE , stdin))
    {
        size_lines = strlen(lines);
        while(i<size_lines){
            //printf("strlen is %d \n",size_lines);
            //printf("last char is <%c> \n", lines[size_lines-3]);
            if(lines[i] != ' ' && lines[i] != '\n' && lines[i] != '\t' && lines[i] != '\0'&& lines[i] != '\r')
            {
                //printf("\n lines [i] is : %c \n",*(lines+i));
                //print
                word[j]=lines[i];
                j++;
                i++;
                //printf("\n<if:>");
            }
            else
            {
                //j++;
                //word[j] = '\0';
                //printf("finish word is '%s' and str is '%s' \n",word,str);

                i++;
                char *temp = word;
                if(similar(word,str,1))
                    printf("%s\n",temp);
                j=0;
                memset(word , 0 , WORD);
            }

            //printf("finally next word! \n",i);
        }
        i=0;
        j=0;
        //memset(lines,0,LINE);
    }
}
//printf("finally i is %d going to next line! \n",i);



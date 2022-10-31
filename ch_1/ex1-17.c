#include <stdio.h>
#define MAXLENGTH 150
#define TARGETLENGTH 10

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len, max = 0;
    char line[MAXLENGTH],longest[MAXLENGTH];
    
    while((len = getline2(line,MAXLENGTH)) > 0)
        if(len > TARGETLENGTH){
	  printf("%s", line);
	}
    return 0;
}

int getline2(char s[],int lim)
{
    int i,c;
    
    for (i=0; i<lim-1 && (c=getchar())!=EOF && (c!='\n'); i++)
        s[i]=c;
    if (c == '\n'){        
        s[i]=c;
        ++i;
    }
    s[i]='\0';       
    return i;
}

void copy(char to[],char from[])
{
    int i = 0;
    
    while ((to[i] = from[i]) != '\0')
        ++i;
}

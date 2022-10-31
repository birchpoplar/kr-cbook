#include <stdio.h>

#define MAXLENGTH 150

int getline2(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char in[], char out[], int len);

int main()
{
    int len, max = 0;
    char line[MAXLENGTH],temp[MAXLENGTH];

    while((len = getline2(line,MAXLENGTH)) > 0) {
      reverse(line, temp, len);
      printf("Original: %s", line);
      printf("Reversed: %s", temp);
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

void reverse(char in[], char out[], int len)
{
  int i,j;
  
  for (i = 2; i < len+1; ++i) {
    out[i-2] = in[len-i];
  }
  out[i-2] = '\n'; 
  ++i;
  out[i-2] = '\0';
}


void copy(char to[],char from[])
{
    int i = 0;
    
    while ((to[i] = from[i]) != '\0')
        ++i;
}

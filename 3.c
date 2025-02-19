//Count of chars,words,lines,blanks in given input

#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
int main(){
    int i,x,a,n;
    char ch[100];
    printf("Enter the input: ");
    scanf("%[^\n]s",ch);
    int charcount=0;
    int wordcount=1;
    int blankcount=0;
    int linecount=1;
    int l=strlen(ch);
    for(i=0;i<l;i++){
        if(isalpha(ch[i]) && ch[i]!=' '){
            charcount++;
        }
        else if(ch[i]==' '){
            wordcount++;
            blankcount++;
        }
        else if(ch[i] == '\n') {
            linecount++;
        }
    }
    printf("Number of characters is: %d\n",charcount);
    printf("Number of words is: %d\n",wordcount);
    printf("Number of blanks is: %d\n",blankcount);
    printf("Number of lines is: %d\n",linecount);
}

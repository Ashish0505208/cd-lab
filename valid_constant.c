//C code to check if given input is int or float

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
int main(){
    int i;
    int count=0;
    char ch[50];
    printf("Enter an integer: ");
    scanf("%s",ch);
    bool isint=true;
    bool isfloat=true;

    if(isdigit(ch[0])){
        isint=true;
        isfloat=true;
    }
    else{
        isint=false;
        isfloat=false;
    }
    int l=strlen(ch);

    for(i=0;i<=l;i++){
        if(ch[i]=='.' && count==0){
            isint=false;
            count++;
        }
        else if(ch[i]=='.' && count>=1){
            isint=false;
            isfloat=false;
        }
    }
    if(isint==true && isfloat==true){
        printf("The entered digit is integer\n");
    }
    else if(isint==false && isfloat==true){
        printf("The entered digit is float number\n");
    }
    else{
        printf("Incorrect digits format\n");
    }
}

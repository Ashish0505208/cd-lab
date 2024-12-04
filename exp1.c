#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
int main(){
    int i,j,n;
    char a[50];
    printf("Enter a string: ");
    scanf("%s",a);
    int l=strlen(a);
    bool isvar=true;
    bool isarray=true;
    bool isfun=true;
    
    if(isalpha(a[0]) || a[0]=='_'){
        isvar=true;
    }
    else{
        isvar=false;
    }

    for(i=1;i<l;i++){
        if(isalpha(a[i]) || isdigit(a[i]) || a[i]=='_'){
            isvar=true;
        }
    }

    if(a[l-3]=='[' && a[l-1]==']' && isdigit(a[l-2])){
        isarray=true;
        isvar=false;
    }
    else{
        isarray=false;
    }

    if(a[l-1]==')' && a[l-2]=='('){
        isfun=true;
        isvar=false;
    }
    else{
        isfun=false;
    }

    if(isvar==true){
        printf("String is a variable\n");
    }
    else{
        printf("STring is not a variable\n");
    }
    if(isarray==true){
        printf("String is a array\n");
    }
    else{
        printf("String is not a array\n");
    }
    if(isfun==true){
        printf("String is a function\n");
    }
    else{
        printf("String is not a function\n");
    }
}

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main() {
//     char str[100];
//     char tok[100];
//     int i=0,j=0;
//     printf("Enter your code here: ");
//     scanf(" %[^\n]", str);
//     const char* keywords[] = {"if", "else", "int", "float", "for", "while", "else if", "return"};
//     while(str[i]!='\0'){
//         if(isspace(str[i])){
//             i++;
//             continue;
//         }
//         if(isalpha(str[i]) || str[i]=='_'){
//             j=0;
//             while(isalnum(str[i]) || str[i]=='_'){
//                 tok[j++]=str[i++];
//             }
//             tok[j]='\0';
//             int keywordflag=0;
//             for(int k=0;k<8;k++){
//                 if(strcmp(tok,keywords[k])==0){
//                     keywordflag=1;
//                     break;
//                 }
//             }
//             if(keywordflag==1){
//                 printf("%s :keyword\n",tok);
//             }
//             else{
//                 printf("%s :identifier\n",tok);
//             }
//         }
//         else if(isdigit(str[i])){
//             j=0;
//             while(isdigit(str[i])){
//                 tok[j++]=str[i++];
//             }
//             tok[j]='\0';
//             printf("%s :number\n",tok);
//         }
//         else{
//             tok[0]=str[i++];
//             tok[1]='\0';
//             if(strchr("+-/*=<>!&|",tok[0])){
//                 printf("%s :operator\n",tok);
//             }
//             else if(strchr(",(){};",tok[0])){
//                 printf("%s :delimiter\n",tok);
//             }
//             else{
//                 printf("Unrecognized token");
//             }
//         }
//     }   
// }


#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char str[100],t[100];
    int i=0,j=0;
    printf("Enter the code: ");
    scanf("%[^\n]",str);
    char* keyword[]={"int","float","for","while","if","else","else if","return"};
    while(str[i]!='\0'){
        if(isspace(str[i])){
            i++;
            continue;
        }
        if(isalpha(str[i]) || str[i]=='_'){
            j=0;
            while(isalnum(str[i]) || str[i]=='_'){
                t[j++]=str[i++];
            }
            t[j]='\0';
            int keywordflag=0;
            for(int k=0;k<8;k++){
                if(strcmp(t,keyword[k])==0){
                    keywordflag=1;
                    break;
                }
            }
            if(keywordflag==1){
                printf("%s - keyword\n",t);
            }else{
                printf("%s - identifier\n",t);
            }
        }
        else if(isdigit(str[i])){
            j=0;
            while(isdigit(str[i])){
                t[j++]=str[i++];
            }
            t[j]='\0';
            printf("%s - number\n",t);
        }
        else{
            t[0]=str[i++];
            t[1]='\0';
            if(strchr("+-/*<>=!",t[0])!=0){
                printf("%s - operator\n",t);
            }
            else if(strchr(",();{}",t[0])!=0){
                printf("%s - delimiter\n",t);
            }
            else{
                printf("%s - unrecognized char\n",t);
            }
        } 
    }
}


// #include<stdio.h>
// #include<string.h>
// #include<ctype.h>
// int main(){
//     char str[100],tok[100];
//     int i=0,j=0;
//     printf("Enter the code: ");
//     scanf("%[^\n]",str);
//     while(str[i]!='\0'){
//         if(isspace(str[i])){
//             i++;
//             continue;
//         }
//         if(isalpha(str[i]) || str[i]=='_'){

//         }
//     }
// }
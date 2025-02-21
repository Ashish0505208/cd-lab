#include<stdio.h>
#include<string.h>
#include<ctype.h>

int ispresent(char arr[],char c){
    for(int i=0;arr[i]!='\0';i++){
        if(arr[i]==c){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n;
    int t=0;
    int nt=0;
    char term[100]={0};
    char nonterm[100]={0};
    printf("Enter the number of productions: ");
    scanf("%d",&n);
    getchar();
    char g[n][100];
    printf("Enter the production rules line by line:\n");
    for(int i=0;i<n;i++){
        scanf("%[^\n]",g[i]);
        getchar();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<strlen(g[i]);j++){
            if(isupper(g[i][j])){
                if(!ispresent(nonterm,g[i][j])){
                    nonterm[nt]=g[i][j];
                    nt++;
                }
            }else if(!isspace(g[i][j]) && g[i][j]!='-' && g[i][j]!='>' && g[i][j]!='|'){
                if(!ispresent(term,g[i][j])){
                    term[t]=g[i][j];
                    t++;
                }
            }
        }
    }
    // printf("Terminals: ");
    // for(int i=0;i<strlen(term);i++){
    //     printf("%c, ",term[i]);
    // }
    // printf("\n");
    // printf("Non-Terminals: ");
    // for(int i=0;i<strlen(nonterm);i++){
    //     printf("%c, ",nonterm[i]);
    // }
    printf("%d,%d",strlen(term),strlen(nonterm));
}
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isterminal(char c){
    return islower(c) || strchr("+-*=",c)!=NULL;
}
int isnonterminal(char c){
    return isupper(c);
}

int iscfg(char g[][100],int n){
    for(int i=0;i<n;i++){
        char left[100],right[100];
        int j=0,k=0;
        while (g[i][j]!='\0' && g[i][j]!='-')
        {
            left[j]=g[i][j];
            j++;
        }
        left[j]='\0';
        if(g[i][j]=='-' && g[i][j+1]=='>'){
            j+=2;
        }else{
            return 0;
        }
        while(g[i][j]!='\0'){
            right[k++]=g[i][j++];
        }
        right[k]='\0';

        if(strlen(left)!=1 || !isnonterminal(left[0])){
            return 0;
        }
        for(int m=0;m<strlen(right);m++){
            if(!isnonterminal(right[m]) && !isterminal(right[m]) && right[m]!='|' && right[m]!=' '){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    int n;
    printf("Enter the number of productions: ");
    scanf("%d",&n);
    getchar();
    char g[n][100];
    printf("Enter the productions line by line: \n");
    for(int i=0;i<n;i++){
        scanf("%[^\n]",g[i]);
        getchar();
    }
    if(iscfg(g,n)){
        printf("Given grammar is CFG\n");
    }else{
        printf("Given grammar is not CFG\n");
    }
}
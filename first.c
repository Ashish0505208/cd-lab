#include <stdio.h>
#include <string.h>
#include <ctype.h>


int n;
char first[10][100], g[10][100];

int isterminal(char c) {
    return islower(c) || strchr("+-*=/", c) != NULL;
}

int isnonterminal(char c) {
    return isupper(c);
}

void add_to_first(int index, char c) {
    if (strchr(first[index], c) == NULL) {
        int len = strlen(first[index]);
        first[index][len] = c;
        first[index][len + 1] = '\0';
    }
}

void find_first(char c, int index) {
    for (int i = 0; i < n; i++) {
        if (g[i][0] == c && g[i][1] == '-' && g[i][2] == '>') { 
            int j = 3; // Start after "->"
            while (j < strlen(g[i])) {
                if (g[i][j] == '|') { 
                    j++; 
                    continue;
                }

                if (isterminal(g[i][j]) || g[i][j] == '$') { 
                    add_to_first(index, g[i][j]);
                } 
                else if (isnonterminal(g[i][j])) { 
                    find_first(g[i][j], index);
                }
                
                while (g[i][j] != '|' && g[i][j] != '\0') j++; 
            }
        }
    }
}

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    getchar();

    printf("Enter the productions line by line:\n");
    for (int i = 0; i < n; i++) {
        scanf("%[^\n]", g[i]);
        getchar();
    }

    for (int i = 0; i < n; i++) {
        first[i][0] = '\0';
        find_first(g[i][0], i);
    }

    printf("\nFIRST sets:\n");
    for (int i = 0; i < n; i++) {
        printf("FIRST(%c) = { ", g[i][0]);
        for (int j = 0; j < strlen(first[i]); j++) {
            printf("%c ", first[i][j]);
        }
        printf("}\n");
    }

    return 0;
}

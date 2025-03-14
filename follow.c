#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n;
char productions[10][100];
char first[10][100];
char follow[10][100];
char non_terminals[10];

int is_terminal(char c) {
    return islower(c) || strchr("+-*/()=", c) != NULL;
}

int is_nonterminal(char c) {
    return isupper(c);
}

void add_to_set(char set[], char c) {
    if (!strchr(set, c)) {
        int len = strlen(set);
        set[len] = c;
        set[len + 1] = '\0';
    }
}

void compute_first(char c, int index) {
    if (is_terminal(c)) {  
        add_to_set(first[index], c);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (productions[i][0] == c) {  
            int j = 3;
            while (j < strlen(productions[i])) {
                if (productions[i][j] == '|') {
                    j++;
                    continue;
                }

                if (is_terminal(productions[i][j])) {
                    add_to_set(first[index], productions[i][j]);
                    break;  
                } else if (is_nonterminal(productions[i][j]) && productions[i][j] != c) {  
                    compute_first(productions[i][j], index);
                }

                while (productions[i][j] != '|' && productions[i][j] != '\0') j++;
            }
        }
    }
}

void compute_follow(char c, int index) {
    if (productions[0][0] == c) {
        add_to_set(follow[index], '$');  
    }

    for (int i = 0; i < n; i++) {
        for (int j = 3; j < strlen(productions[i]); j++) {
            if (productions[i][j] == c) {  
                if (productions[i][j + 1] != '\0' && productions[i][j + 1] != '|') {  
                    if (is_terminal(productions[i][j + 1])) {
                        add_to_set(follow[index], productions[i][j + 1]);
                    } else {
                        int k;
                        for (k = 0; k < n; k++) {
                            if (productions[k][0] == productions[i][j + 1]) {
                                strcat(follow[index], first[k]);
                            }
                        }
                    }
                } else {  
                    int k;
                    for (k = 0; k < n; k++) {
                        if (productions[k][0] == productions[i][0]) {
                            strcat(follow[index], follow[k]);
                        }
                    }
                }
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
        scanf("%[^\n]", productions[i]);
        getchar();
        non_terminals[i] = productions[i][0];
    }

    for (int i = 0; i < n; i++) {
        first[i][0] = '\0';
        follow[i][0] = '\0';
    }

    for (int i = 0; i < n; i++) {
        compute_first(non_terminals[i], i);
    }

    for (int i = 0; i < n; i++) {
        compute_follow(non_terminals[i], i);
    }

    printf("\nFIRST sets:\n");
    for (int i = 0; i < n; i++) {
        printf("FIRST(%c) = { ", non_terminals[i]);
        for (int j = 0; j < strlen(first[i]); j++) {
            printf("%c ", first[i][j]);
        }
        printf("}\n");
    }

    printf("\nFOLLOW sets:\n");
    for (int i = 0; i < n; i++) {
        printf("FOLLOW(%c) = { ", non_terminals[i]);
        for (int j = 0; j < strlen(follow[i]); j++) {
            printf("%c ", follow[i][j]);
        }
        printf("}\n");
    }

    return 0;
}

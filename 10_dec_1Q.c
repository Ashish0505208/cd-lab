//converting A->a, A->b to A->a|b

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void processProductions(int n, char grammar[n][100]) {
    char finalGrammar[n][100];
    int finalCount = 0;

    for (int i = 0; i < n; i++) {
        char left[100], right[100];
        int j = 0, k = 0;

        while (grammar[i][j] != '\0' && grammar[i][j] != '-') {
            left[j] = grammar[i][j];
            j++;
        }
        left[j] = '\0';

        j += 2;

        while (grammar[i][j] != '\0') {
            right[k++] = grammar[i][j++];
        }
        right[k] = '\0';

        if (strcmp(right, "ε") == 0) {
            strcpy(right, "$");
        }

        int found = 0;
        for (int x = 0; x < finalCount; x++) {
            if (strncmp(finalGrammar[x], left, strlen(left)) == 0) {
                int len = strlen(finalGrammar[x]);
                if (strstr(finalGrammar[x], right) == NULL) {
                    if (len > strlen(left) + 2) {
                        finalGrammar[x][len] = '|';
                        finalGrammar[x][len + 1] = '\0';
                    }
                    strcat(finalGrammar[x], right);
                }
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(finalGrammar[finalCount], left);
            strcat(finalGrammar[finalCount], "->");
            strcat(finalGrammar[finalCount], right);
            finalCount++;
        }
    }

    printf("Final Grammar:\n");
    for (int i = 0; i < finalCount; i++) {
        printf("%s\n", finalGrammar[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of production rules: ");
    scanf("%d", &n);
    getchar();

    char grammar[n][100];
    printf("Enter the grammar line by line:\n");
    for (int i = 0; i < n; i++) {
        fgets(grammar[i], 100, stdin);
        grammar[i][strcspn(grammar[i], "\n")] = '\0';
    }

    processProductions(n, grammar);

    return 0;
}

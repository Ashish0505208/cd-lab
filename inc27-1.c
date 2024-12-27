#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isNonTerminal(char c) {
    return isupper(c);
}

int isTerminal(char c) {
    return islower(c) || isdigit(c) || c == '+' || c == '*' || c == '/' || c == '-' || c == '=';
}

void countTerminalsAndNonTerminals(char grammar[][100], int n, int *termCount, int *nonTermCount) {
    for (int i = 0; i < n; i++) {
        char left[100];
        char right[100];
        int j = 0, k = 0;

        while (grammar[i][j] != '\0' && grammar[i][j] != '-') {
            left[j] = grammar[i][j];
            j++;
        }
        left[j] = '\0';

        j++;
        while (grammar[i][j] != '\0') {
            right[k++] = grammar[i][j++];
        }
        right[k] = '\0';

        if (isNonTerminal(left[0])) {
            (*nonTermCount)++;
        }

        for (int m = 0; m < strlen(right); m++) {
            if (isTerminal(right[m])) {
                (*termCount)++;
            } else if (isNonTerminal(right[m])) {
                (*nonTermCount)++;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of production rules: ");
    scanf("%d", &n);
    getchar();

    char grammar[n][100];
    printf("Enter the grammar (in form of A->B | C, one production per line):\n");
    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", grammar[i]);
    }

    int termCount = 0;
    int nonTermCount = 0;
    countTerminalsAndNonTerminals(grammar, n, &termCount, &nonTermCount);

    printf("Number of Terminals: %d\n", termCount);
    printf("Number of Non-Terminals: %d\n", nonTermCount);

    return 0;
}

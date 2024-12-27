#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isNonTerminal(char c) {
    return isupper(c);
}

int isTerminal(char c) {
    return islower(c) || isdigit(c) || c == '+' || c == '*' || c == '/' || c == '-' || c == '=';
}

int isCFG(char grammar[][100], int n) {
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

        if (strlen(left) != 1 || !isNonTerminal(left[0])) {
            return 0;
        }

        for (int m = 0; m < strlen(right); m++) {
            if (!isTerminal(right[m]) && !isNonTerminal(right[m]) && right[m] != ' ' && right[m] != '|') {
                return 0;
            }
        }
    }
    return 1;
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

    if (isCFG(grammar, n)) {
        printf("The given grammar is a Context-Free Grammar (CFG).\n");
    } else {
        printf("The given grammar is NOT a Context-Free Grammar (CFG).\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a non-terminal
int isNonTerminal(char c) {
    return isupper(c);
}

// Function to check if a character is a terminal
int isTerminal(char c) {
    return islower(c) || strchr("+-*/= ", c) != NULL;
}

// Function to check if the grammar is Context-Free Grammar (CFG)
int isCFG(char grammar[][100], int n) {
    for (int i = 0; i < n; i++) {
        char left[100], right[100];
        int j = 0, k = 0;

        // Extract the left-hand side (LHS)
        while (grammar[i][j] != '\0' && grammar[i][j] != '-') {
            left[j] = grammar[i][j];
            j++;
        }
        left[j] = '\0';

        // Skip '->'
        if (grammar[i][j] == '-' && grammar[i][j + 1] == '>') {
            j += 2;
        } else {
            return 0; // Invalid production rule format
        }

        // Extract the right-hand side (RHS)
        while (grammar[i][j] != '\0') {
            right[k++] = grammar[i][j++];
        }
        right[k] = '\0';

        // Validate LHS: Must be a single non-terminal
        if (strlen(left) != 1 || !isNonTerminal(left[0])) {
            return 0;
        }

        // Validate RHS: Allowed characters are terminals, non-terminals, '|', and spaces
        for (int m = 0; m < strlen(right); m++) {
            if (!isTerminal(right[m]) && !isNonTerminal(right[m]) && right[m] != '|' && right[m] != ' ') {
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
    printf("Enter the grammar (in the form A->B | C, one production per line):\n");
    for (int i = 0; i < n; i++) {
        scanf("%[^\n]",grammar[i]);
        getchar();
    }

    if (isCFG(grammar, n)) {
        printf("The given grammar is a Context-Free Grammar (CFG).\n");
    } else {
        printf("The given grammar is NOT a Context-Free Grammar (CFG).\n");
    }

    return 0;
}
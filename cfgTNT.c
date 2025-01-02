#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isNonTerminal(char c) {
    return isupper(c);
}

int isTerminal(char c) {
    return (islower(c) || isdigit(c) || strchr("+-*", c) != NULL);
}

int removeDuplicates(char array[], int size) {
    int uniqueIndex = 0;
    for (int i = 0; i < size; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < uniqueIndex; j++) {
            if (array[i] == array[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            array[uniqueIndex++] = array[i];
        }
    }
    return uniqueIndex;
}

int main() {
    int n;
    printf("Enter the number of production rules: ");
    scanf("%d", &n);
    getchar();

    char grammar[n][100];
    printf("Enter the grammar (in the form A->B | C, one production per line):\n");
    for (int i = 0; i < n; i++) {
        fgets(grammar[i], 100, stdin);
        grammar[i][strcspn(grammar[i], "\n")] = '\0';
    }

    char terminals[256] = {0};
    char nonTerminals[256] = {0};
    int termCount = 0, nonTermCount = 0;

    for (int i = 0; i < n; i++) {
        char left[100], right[100];
        int j = 0, k = 0;

        // (LHS)
        while (grammar[i][j] != '\0' && grammar[i][j] != '-') {
            left[j] = grammar[i][j];
            j++;
        }
        left[j] = '\0';

        // Skip '->'
        j += 2;

        //(RHS)
        while (grammar[i][j] != '\0') {
            right[k++] = grammar[i][j++];
        }
        right[k] = '\0';


        if (isNonTerminal(left[0])) {
            nonTerminals[nonTermCount++] = left[0];
        }


        for (int m = 0; m < strlen(right); m++) {
            if (isTerminal(right[m])) {
                terminals[termCount++] = right[m];
            } else if (isNonTerminal(right[m])) {
                nonTerminals[nonTermCount++] = right[m];
            }
        }
    }

    termCount = removeDuplicates(terminals, termCount);
    nonTermCount = removeDuplicates(nonTerminals, nonTermCount);

    printf("Number of Terminals: %d\n", termCount);
    printf("Number of Non-Terminals: %d\n", nonTermCount);

    return 0;
}
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


bool isLeftRecursive(char *production) {
    char nonTerminal = production[0];
    char *rightHandSide = strchr(production, '>') + 1;

    char *alternative = strtok(rightHandSide, "|");
    while (alternative != NULL) {
        if (alternative[0] == nonTerminal) {
            return true;
        }
        alternative = strtok(NULL, "|");
    }
    return false;
}

int main() {
    int n;
    bool isLeftRec = false;

    printf("Enter the number of production rules: ");
    scanf("%d", &n);

    char grammar[n][100];

    printf("Enter the production rules\n");
    for (int i = 0; i < n; i++) {
        scanf("%s",grammar[i]);
    }

    for (int i = 0; i < n; i++) {
        if (isLeftRecursive(grammar[i])) {
            isLeftRec = true;
            break;
        }
    }

    if (isLeftRec) {
        printf("The grammar is left recursive\n");
    } else {
        printf("The grammar is not left recursive\n");
    }
}
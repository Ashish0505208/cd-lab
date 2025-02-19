#include <stdio.h>
#include <string.h>

void eliminateLeftFactoring(char *left, char *right) {
    char prefix[50], suffix[25][50];
    int i = 0, j = 0, k = 0, count = 0;
    int flag = 0;

    // Split the right-hand side into alternatives
    while (right[k] != '\0') {
        if (right[k] == '|') {
            suffix[count][j] = '\0';
            count++;
            j = 0;
        } else {
            suffix[count][j++] = right[k];
        }
        k++;
    }
    suffix[count][j] = '\0';
    count++;

    // Find the common prefix
    int prefixLen = 0;
    while (suffix[0][prefixLen] != '\0') {
        for (i = 1; i < count; i++) {
            if (suffix[0][prefixLen] != suffix[i][prefixLen]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) break;
        prefix[prefixLen] = suffix[0][prefixLen];
        prefixLen++;
    }
    prefix[prefixLen] = '\0';

    if (prefixLen == 0) {
        printf("The given grammar has NO left factoring.\n");
        return;
    }

    // Print the updated grammar
    printf("The productions after eliminating left factoring are:\n");
    printf("%s->%s%s'\n", left, prefix, left);
    printf("%s'->", left);
    for (i = 0; i < count; i++) {
        if (strlen(suffix[i] + prefixLen) == 0) {
            printf("$");
        } else {
            printf("%s", suffix[i] + prefixLen);
        }
        if (i < count - 1) {
            printf("|");
        }
    }
    printf("\n");
}

int main() {
    char left[10], right[100];

    printf("Enter the production (e.g., A->aB|aC|d): ");
    scanf("%1s->%s", left, right);

    eliminateLeftFactoring(left, right);

    return 0;
}

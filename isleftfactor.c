#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the grammar is left factored
bool isLeftFactored(char *left, char *right) {
    char first[25][50];
    int i = 0, j = 0, k = 0, count = 0;

    // Split the right-hand side by '|'
    while (right[k] != '\0') {
        if (right[k] == '|') {
            first[count][j] = '\0';
            count++;
            j = 0;
        } else {
            first[count][j++] = right[k];
        }
        k++;
    }
    first[count][j] = '\0';
    count++;

    // Check if any two alternatives have the same prefix
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (first[i][0] == first[j][0]) {
                return true; // Left factoring detected
            }
        }
    }
    return false; // No left factoring
}

int main() {
    char left[10], right[100];

    printf("Enter the production (e.g., A->aB|aC|d): ");
    scanf("%1s->%s", left, right);

    if (isLeftFactored(left, right)) {
        printf("The given grammar is left factored\n");
    } else {
        printf("The given grammar is not left factored\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

void main() {
    char left[10], right[100], temp[50], productions[25][50];
    int i = 0, j = 0, flag = 0, consumed = 0;

    // Input: Grammar production
    printf("Enter the production (e.g., A->Ax|B): ");
    scanf("%1s->%s", left, right);
    printf("%s\n", right); // Print right-hand side for reference

    // Process each alternative separated by '|'
    while (consumed < strlen(right)) {
        int k = 0;

        // Extract each part before '|'
        while (right[consumed] != '|' && right[consumed] != '\0') {
            temp[k++] = right[consumed++];
        }
        temp[k] = '\0'; // Null-terminate the current alternative
        consumed++;     // Move past '|'

        // Check for left recursion
        if (temp[0] == left[0]) {
            flag = 1; // Left recursion detected
            // Store the left-recursive part in the form: A'->remaining part + A'
            sprintf(productions[i++], "%s'->%s%s'", left, temp + 1, left);
        } else {
            // Store the non-left-recursive part in the form: A->part + A'
            sprintf(productions[i++], "%s->%s%s'", left, temp, left);
        }
    }

    // If left recursion was found, print updated grammar
    if (flag == 1) {
        // Add epsilon (null) production: A' -> $
        sprintf(productions[i++], "%s'->$", left);
        printf("The productions after eliminating Left Recursion are:\n");

        // First, print the non-left-recursive parts
        for (j = 0; j < i; j++) {
            if (strstr(productions[j], "'->") == NULL) {
                printf("%s\n", productions[j]);
            }
        }

        // Then, print the left-recursive parts
        for (j = 0; j < i; j++) {
            if (strstr(productions[j], "'->") != NULL) {
                printf("%s\n", productions[j]);
            }
        }
    } else {
        printf("The Given Grammar has no Left Recursion\n");
    }
}

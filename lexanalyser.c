#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100];
    char token[100];
    int i = 0, j = 0;
    const char* keywords[] = {"int", "float", "double", "char", "void", "if", "else", "while", "for"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    printf("Enter code to analyze: ");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {
        if (isspace(input[i])) {
            i++;
            continue;
        }

        if (isalpha(input[i]) || input[i] == '_') {
            j = 0;
            while (isalnum(input[i]) || input[i] == '_') {
                token[j++] = input[i++];
            }
            token[j] = '\0';

            int isKeywordFlag = 0;
            for (int k = 0; k < numKeywords; k++) {
                if (strcmp(token, keywords[k]) == 0) {
                    isKeywordFlag = 1;
                    break;
                }
            }
            if (isKeywordFlag) {
                printf("%s - keyword\n", token);
            } else {
                printf("%s - identifier\n", token);
            }
        }
        else if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("%s - number\n", token);
        }
        else {
            token[0] = input[i++];
            token[1] = '\0';

            if (strchr("+-*/=<>!&|", token[0])) {
                printf("%s - operator\n", token);
            }
            else if (strchr(";,(){}", token[0])) {
                printf("%s - delimiter\n", token);
            }
            else {
                printf("Unrecognized token: %s\n", token);
            }
        }
    }

    return 0;
}
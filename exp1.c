#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isVariable(char a[]) {
    if (!isalpha(a[0]) && a[0] != '_') {
        return false;
    }
    for (int i = 1; i < strlen(a); i++) {
        if (!(isalnum(a[i]) || a[i] == '_')) {
            return false;
        }
    }
    return true;
}

bool isArray(char a[]) {
    int len = strlen(a);
    if (len < 3 || a[len - 1] != ']' || a[len - 2] != '[') {
        return false;
    }
    if (!isdigit(a[len - 3])) {
        return false;
    }
    for (int i = 0; i < len - 3; i++) {
        if (!(isalnum(a[i]) || a[i] == '_')) {
            return false;
        }
    }
    return true;
}

bool isFunction(char a[]) {
    int len = strlen(a);
    if (len < 3 || a[len - 1] != ')' || a[len - 2] != '(') {
        return false;
    }
    for (int i = 0; i < len - 2; i++) {
        if (!(isalnum(a[i]) || a[i] == '_')) {
            return false;
        }
    }
    return true;
}

int main() {
    char a[20];
    printf("Enter a string:\n");
    scanf("%s", a);

    if (isVariable(a)) {
        printf("The given string is a variable\n");
    } else {
        printf("The given string is not a variable\n");
    }

    if (isArray(a)) {
        printf("The given string is an array\n");
    } else {
        printf("The given string is not an array\n");
    }

    if (isFunction(a)) {
        printf("The given string is a function\n");
    } else {
        printf("The given string is not a function\n");
    }

    return 0;
}

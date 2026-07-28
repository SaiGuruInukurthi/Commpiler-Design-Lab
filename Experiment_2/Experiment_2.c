#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i = 0;
    int state = 0;

    printf("Enter an identifier: ");
    scanf("%s", str);

    while (str[i] != '\0') {

        switch(state) {

            case 0:
                if (isalpha(str[i]) || str[i] == '_') {
                    state = 1;
                }
                else {
                    printf("Invalid identifier");
                    return 0;
                }
                break;

            case 1:
                if (isalpha(str[i]) || isdigit(str[i]) || str[i] == '_') {
                    state = 1;
                }
                else {
                    if (str[i] == '[') {
                        printf("Identifier is an Array");
                        return 0;
                    }
                    else if (str[i] == '(') {
                        printf("Identifier is a Function");
                        return 0;
                    }
                    else {
                        printf("Identifier is a Variable");
                        return 0;
                    }
                }
                break;
        }

        i++;
    }

    printf("Identifier is a Variable");

    return 0;
}
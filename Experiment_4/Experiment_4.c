#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input[500];
    char token[50];
    int state = 0;
    int j = 0;

    printf("Enter the program (Press Enter twice to finish):\n");

    int len = 0;
    while (fgets(input + len, sizeof(input) - len, stdin))
    {
        if (strcmp(input + len, "\n") == 0)
            break;
        len = strlen(input);
    }

    int i = 0;

    while (1)
    {
        char ch = input[i];

        switch (state)
        {
            case 0:

                if (isalpha(ch) || ch == '_')
                {
                    token[j++] = ch;
                    state = 1;
                    i++;
                }
                else if (isdigit(ch))
                {
                    token[j++] = ch;
                    state = 2;
                    i++;
                }

                // Multi-character operators
                else if ((ch == '=' && input[i+1] == '=') ||
                         (ch == '!' && input[i+1] == '=') ||
                         (ch == '<' && input[i+1] == '=') ||
                         (ch == '>' && input[i+1] == '=') ||
                         (ch == '&' && input[i+1] == '&') ||
                         (ch == '|' && input[i+1] == '|'))
                {
                    printf("%-10.2s Operator\n", &input[i]);
                    i += 2;
                }

                // Single-character operators
                else if (ch == '+' || ch == '-' || ch == '*' ||
                         ch == '/' || ch == '%' || ch == '=' ||
                         ch == '<' || ch == '>' || ch == '!')
                {
                    printf("%-10c Operator\n", ch);
                    i++;
                }

                // Brackets
                else if (ch == '{' || ch == '}' ||
                         ch == '(' || ch == ')' ||
                         ch == '[' || ch == ']')
                {
                    printf("%-10c Bracket\n", ch);
                    i++;
                }

                // Punctuators
                else if (ch == ',' || ch == ';')
                {
                    printf("%-10c Punctuator\n", ch);
                    i++;
                }

                else if (ch == ' ' || ch == '\t' || ch == '\n')
                {
                    i++;
                }
                else if (ch == '\0')
                {
                    return 0;
                }
                else
                {
                    printf("%-10c Invalid Token\n", ch);
                    i++;
                }
                break;

            case 1: // Identifier / Keyword

                if (isalnum(ch) || ch == '_')
                {
                    token[j++] = ch;
                    i++;
                }
                else
                {
                    token[j] = '\0';

                    if (strcmp(token, "int") == 0 ||
                        strcmp(token, "float") == 0 ||
                        strcmp(token, "char") == 0 ||
                        strcmp(token, "if") == 0 ||
                        strcmp(token, "else") == 0 ||
                        strcmp(token, "while") == 0 ||
                        strcmp(token, "return") == 0)
                        printf("%-10s Keyword\n", token);
                    else
                        printf("%-10s Identifier\n", token);

                    j = 0;
                    state = 0;
                }
                break;

            case 2: // Integer constant

                if (isdigit(ch))
                {
                    token[j++] = ch;
                    i++;
                }
                else
                {
                    token[j] = '\0';
                    printf("%-10s Integer Constant\n", token);

                    j = 0;
                    state = 0;
                }
                break;
        }
    }

    return 0;
}
#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i = 0;
    int state = 0;

    printf("Enter constant: ");
    scanf("%s", str);

    while(str[i] != '\0')
    {
        switch(state)
        {
            case 0:
                if(isdigit(str[i]))
                    state = 1;
                else
                {
                    printf("Invalid Constant");
                    return 0;
                }
                break;

            case 1:
                if(isdigit(str[i]))
                    state = 1;
                else if(str[i] == '.')
                    state = 3;
                else
                {
                    printf("Invalid Constant");
                    return 0;
                }
                break;

            case 3:
                if(isdigit(str[i]))
                    state = 3;
                else
                {
                    printf("Invalid Constant");
                    return 0;
                }
                break;
        }

        i++;
    }

    if(state == 1)
        printf("Integer Constant");
    else if(state == 3)
        printf("Real Constant");
    else
        printf("Invalid Constant");

    return 0;
}
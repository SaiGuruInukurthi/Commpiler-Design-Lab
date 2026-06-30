#include<stdio.h>
#include<string.h>

int main(){
    char str[100];
    int state = 0;
    int i;
    
    printf("Enter a string (only with a and b: ");
    scanf("%s",str);
    
    for (i = 0; str[i] != '\0'; i++){
        switch(state){
            case 0:
                if (str[i] == 'a'){
                    state = 1;
                }
                else if (str[i] == 'b'){
                    state = 3;
                }
                else{
                    printf("Invalid input");
                    return 0;
                }
            break;
            case 1:
                if (str[i] == 'a'){
                    state = 2;
                }
                else if (str[i] == 'b'){
                    state = 3;
                }
                else{
                    printf("Invalid input");
                    return 0;
                }
            break;
            case 2:
                if (str[i] == 'a'){
                    state = 2;
                }
                else if (str[i] == 'b'){
                    state = 2;
                }
                else{
                    printf("Invalid input");
                    return 0;
                }
            break;
            case 3:
                if (str[i] == 'a'){
                    state = 3;
                }
                else if (str[i] == 'b'){
                    state = 3;
                }
                else{
                    printf("Invalid input");
                    return 0;
                }
            break;
        }
    }
    
    if (state == 2){
        printf("String accepted");
    }else{
        printf("String rejected");
    }
    
    return 0;
}
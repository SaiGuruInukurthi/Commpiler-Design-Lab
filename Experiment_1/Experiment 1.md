# Experiment 1: Recognition of Strings Using Finite Automata

**Aim:** Implementation of DFA to Accept the following strings over `{a, b}`.

a) Accept all strings that end with `abb`.

b) Accept all strings that begin with `aa`.

c) Accept all strings that begin with `a` and end with `b`.

d) Accept all strings that contain the substring `bab`.

## Design (Transition Diagram)

> *Draw the transition diagram for each DFA.*

## Algorithm

> *Write the algorithm for each DFA.*

## Program

### a) Accept all strings that end with `abb`

```c
#include <stdio.h>
#include <string.h>

int main()
{
 char str[100];
 int state = 0;
 int i;

 printf("Enter a string (only a and b): ");
 scanf("%s", str);

 for(i = 0; str[i] != '\0'; i++)
 {
 switch(state)
 {
 case 0:
 if(str[i] == 'a')
 state = 1;
 else if(str[i] == 'b')
 state = 0;
 else
 {
 printf("Invalid Input!\n");
 return 0;
 }
 break;

 case 1:
 if(str[i] == 'a')
 state = 1;
 else if(str[i] == 'b')
 state = 2;
 else
 {
 printf("Invalid Input!\n");
 return 0;
 }
 break;

 case 2:
 if(str[i] == 'a')
 state = 1;
 else if(str[i] == 'b')
 state = 3;
 else
 {
 printf("Invalid Input!\n");
 return 0;
 }
 break;

 case 3:
 if(str[i] == 'a')
 state = 1;
 else if(str[i] == 'b')
 state = 0;
 else
 {
 printf("Invalid Input!\n");
 return 0;
 }
 break;
 }
 }

 if(state == 3)
 printf("String Accepted\n");
 else
 printf("String Rejected\n");

 return 0;
}
```

### Output

> *Sample output:*

### Result

> *Write the result here.*

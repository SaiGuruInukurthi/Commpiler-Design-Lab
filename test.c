#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PI 3.141592653589793
#define SQUARE(x) ((x) * (x))
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

typedef union {
    int i;
    float f;
    char bytes[4];
} Data;

typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {

    printf("=== C Compiler Test Program ===\n\n");

    printf("Compiler supports C!\n\n");

    // Data Types
    int integer = 42;
    float decimal = 3.14f;
    double bigDecimal = PI;
    char letter = 'A';
    _Bool flag = 1;

    printf("Integer : %d\n", integer);
    printf("Float   : %.2f\n", decimal);
    printf("Double  : %.10lf\n", bigDecimal);
    printf("Char    : %c\n", letter);
    printf("Bool    : %d\n\n", flag);

    // Arithmetic
    printf("Arithmetic\n");
    printf("10 + 5 = %d\n", 10 + 5);
    printf("10 - 5 = %d\n", 10 - 5);
    printf("10 * 5 = %d\n", 10 * 5);
    printf("10 / 5 = %d\n", 10 / 5);
    printf("10 %% 3 = %d\n\n", 10 % 3);

    // Bitwise
    printf("Bitwise Operations\n");
    printf("5 & 3 = %d\n", 5 & 3);
    printf("5 | 3 = %d\n", 5 | 3);
    printf("5 ^ 3 = %d\n", 5 ^ 3);
    printf("5 << 1 = %d\n", 5 << 1);
    printf("5 >> 1 = %d\n\n", 5 >> 1);

    // Arrays
    int numbers[] = {9, 3, 7, 1, 5};

    printf("Original Array:\n");
    printArray(numbers, ARRAY_SIZE(numbers));

    qsort(numbers, ARRAY_SIZE(numbers), sizeof(int), compare);

    printf("Sorted Array:\n");
    printArray(numbers, ARRAY_SIZE(numbers));
    printf("\n");

    // Strings
    char str1[100] = "Hello";
    char str2[] = " Compiler";

    strcat(str1, str2);

    printf("String: %s\n", str1);
    printf("Length: %zu\n\n", strlen(str1));

    // Pointers
    int value = 100;
    int *ptr = &value;

    printf("Pointer Demo\n");
    printf("Address : %p\n", (void*)ptr);
    printf("Value   : %d\n\n", *ptr);

    // Dynamic Memory
    int *dynamic = malloc(5 * sizeof(int));

    if (dynamic == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
        dynamic[i] = i * i;

    dynamic = realloc(dynamic, 10 * sizeof(int));

    for (int i = 5; i < 10; i++)
        dynamic[i] = i * i;

    printf("Dynamic Memory:\n");

    for (int i = 0; i < 10; i++)
        printf("%d ", dynamic[i]);

    printf("\n\n");

    free(dynamic);

    // Structures
    Student s = {"Alice", 20, 9.2f};

    printf("Structure\n");
    printf("Name : %s\n", s.name);
    printf("Age  : %d\n", s.age);
    printf("GPA  : %.2f\n\n", s.gpa);

    // Union
    Data d;
    d.i = 12345;

    printf("Union Integer : %d\n", d.i);
    d.f = 12.5f;
    printf("Union Float   : %.2f\n\n", d.f);

    // Enum
    Color c = GREEN;

    printf("Enum Value = %d\n\n", c);

    // Function Pointer
    int (*operation)(int, int);

    operation = add;
    printf("Add: %d\n", operation(8, 5));

    operation = multiply;
    printf("Multiply: %d\n\n", operation(8, 5));

    // Recursion
    printf("Factorial(6) = %d\n\n", factorial(6));

    // Loops

    printf("For Loop:\n");

    for (int i = 1; i <= 5; i++)
        printf("%d ", i);

    printf("\n");

    printf("While Loop:\n");

    int i = 0;

    while (i < 5)
        printf("%d ", i++);

    printf("\n");

    printf("Do-While Loop:\n");

    i = 0;

    do {
        printf("%d ", i++);
    } while (i < 5);

    printf("\n\n");

    // Switch
    printf("Switch Statement:\n");

    switch (c) {
        case RED:
            printf("RED\n");
            break;
        case GREEN:
            printf("GREEN\n");
            break;
        case BLUE:
            printf("BLUE\n");
            break;
    }

    printf("\n");

    // Random Numbers
    srand((unsigned)time(NULL));

    printf("Random Numbers:\n");

    for (int j = 0; j < 5; j++)
        printf("%d ", rand() % 100);

    printf("\n\n");

    // File I/O
    FILE *fp = fopen("compiler_test.txt", "w");

    if (fp != NULL) {
        fprintf(fp, "This file was generated successfully.\n");
        fclose(fp);

        fp = fopen("compiler_test.txt", "r");

        if (fp != NULL) {
            char buffer[256];

            printf("Reading File:\n");

            while (fgets(buffer, sizeof(buffer), fp))
                printf("%s", buffer);

            fclose(fp);
        }
    }

    printf("\n");

    // Command Line Arguments
    printf("Command Line Arguments (%d):\n", argc);

    for (int j = 0; j < argc; j++)
        printf("argv[%d] = %s\n", j, argv[j]);

    printf("\n");

    // Macro
    printf("SQUARE(12) = %d\n\n", SQUARE(12));

    printf("=== ALL TESTS COMPLETED SUCCESSFULLY ===\n");

    return 0;
}
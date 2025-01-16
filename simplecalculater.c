#include <stdio.h>

// Function to add two numbers
int add(int num1, int num2) {
    return num1 + num2;
}

// Function to subtract two numbers
int subtract(int num1, int num2) {
    return num1 - num2;
}
 // function multiply
 int multi(int num1, int num2) {
    return num1 * num2;
}
// function for division
int division(int num1, int num2) {
    return num1 / num2;
}

int main() {
    int num1, num2;
    char operation;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    
    while(1)
    {
        printf("Enter operation (+ for addition, - for subtraction , * for multiplication , / for division , E for exiting ) :  ");
        scanf(" %c", &operation);
        switch (operation) {
            case '+':
                printf("%d + %d = %d\n", num1, num2, add(num1, num2));
                break;
            case '-':
                printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
                break;
            case '*':
                printf("%d * %d = %d\n", num1, num2, multi(num1, num2));
                break;
            case '/':
                printf("%d / %d = %d\n", num1, num2, division(num1, num2));
                break;
            
            default:
                printf("Invalid operation. Please use + or -.\n");
        }
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 20
char stack[max];
int top = -1;

void push(int value) {
    if (top == max - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = value;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack empty\n");
        return -1; // Return a sentinel value
    } else {
        return stack[top--];
    }
}

int main() {
    char s[max];
    printf("Enter the postfix expression: ");
    scanf("%s", s);
    
    int i = 0;
    int l = strlen(s);
    
    while (s[i] != '\0') {
        // Check if the character is a digit
        if (isdigit(s[i])) {
            // Convert character to integer and push onto stack
            push(s[i] - '0'); // Convert char to int
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            int b = pop(); // Second operand
            int a = pop(); // First operand
            int r = 0;
            char symbol = s[i];
            switch (symbol) {
                case '+':
                    r = a + b;
                    break;
                case '-':
                    r = a - b;
                    break;
                case '*':
                    r = a * b;
                    break;
                case '/':
                    if (b != 0) {
                        r = a / b;
                    } else {
                        printf("Division by zero error\n");
                        return 1; // Exit on error
                    }
                    break;
            }
            push(r); // Push the result back onto the stack
        }
        i++;
    }
    
    int res = pop();
    if (top == -1) { // Check if the stack is empty
        printf("Result: %d\n", res);
    } else {
        printf("Error: The stack is not empty after evaluation\n");
    }

    return 0;
}
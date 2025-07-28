#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Stack operations
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    int i, operand1, operand2, result;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
            // Convert character to integer and push
            push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            operand2 = pop();
            operand1 = pop();

            switch (ch) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0) {
                    printf("Division by zero error\n");
                    exit(1);
                }
                result = operand1 / operand2;
                break;
            default:
                printf("Unknown operator: %c\n", ch);
                exit(1);
            }
            push(result);
        }
    }

    return pop(); // Final result
}

int main() {
    char postfix[MAX];
    int result;

    printf("Enter a postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    result = evaluatePostfix(postfix);

    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}
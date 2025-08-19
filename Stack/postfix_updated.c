
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack implementation
double stack[MAX];
int top = -1;

void push(double value) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

double pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Function to evaluate postfix expression
double evaluatePostfix(char* expr) {
    char* token = strtok(expr, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Operand: push to stack
            push(atof(token));
        } else {
            // Operator: pop two operands
            double val2 = pop();
            double val1 = pop();

            switch (token[0]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
	     case '^': push(pow(val1, val2)); break;
                default:
                    printf("Unsupported operator: %s\n", token);
                    exit(1);
            }
        }

        token = strtok(NULL, " ");
    }

    return pop();  // Final result
}

int main() {
    char expr[200];

    printf("Enter postfix expression (tokens separated by space):\n");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0; // Remove trailing newline

    double result = evaluatePostfix(expr);
    printf("Result = %.2lf\n", result);

    return 0;
}


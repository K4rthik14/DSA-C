// program to perform a evaluevation of a postfix equation.
 #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
int stack[100];
int top = -1;

void push(int value){
    if(top == MAX -1){
        printf("StackOVerflow\n");
        exit(1);

    }
 stack [++top] = value;

}

int pop(){
    if(top == -1 ){
        printf("Stack Underflow");
        exit(1);
    }
    return stack[top--];

}

int evaluatePostfix(char postfix[]){
    int i, ope1, ope2, result;
    char ch;
    for(i=0; postfix[i] != '\0'; i++){
        ch = postfix[i];

        if(isdigit(ch)){
            push(ch - '0');

        } else if(ch == '+'||ch == '*'||ch == '-'||ch == '/')
        {
            ope2= pop();
            ope1= pop();

            switch(ch){
                case '+':
                result = ope1 + ope2;
                break;
                case '-':
                result = ope1 - ope2;
                break;
                case '*':
                result = ope1 * ope2;
                break;
                case '/':
                if(ope2==0){
                    printf("Division by zero error\n");
                    exit(1);
                }
            result = ope1 / ope2;
            break;
        default:
         printf("Unknown Operator: %c\n");
         exit(1);

            }
 
        push(result);
        }
    }
    return pop();

}
void main(){
    char postfix[MAX];
    char result;
    printf("Enter a postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    result = evaluatePostfix(postfix);

    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}


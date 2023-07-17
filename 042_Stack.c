#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_SIZE 100

long Stack[STACK_SIZE];
int stack_pointer = 0;

int is_Empty(){
    return stack_pointer == 0;
}

void push(long x){
    if(stack_pointer <= STACK_SIZE){
        Stack[stack_pointer++] = x;                 //[++x] と [x++] の二通りがある
    }
    else{
        printf("Stack is full!\n");
    }
}

char pop(){
    if(stack_pointer <= 0){
        printf("Stack is empty!\n");
        return -1;
    }
    return Stack[--stack_pointer];                  //[--x] と [x--] の二通りがある
}

int main(){
    long a, b, x; 
    int character;

    while((character = getchar()) != EOF){
        if(isdigit(character)){
            ungetc(character, stdin);
            scanf_s("%ld", &x);
            push(x);
        }
        else {
            switch(character){
                case '+'  : 
                    b = pop(); a = pop();
                    push(a + b);
                    break;
                case '-'  : 
                    b = pop(); a = pop();
                    push(a - b);
                    break;
                case '*'  :
                    b = pop(); a = pop();
                    push(a * b);
                    break;
                case '/'  :
                    b = pop(); a = pop();
                    push(a / b);
                    break;
                case '\n' :
                    if(!is_Empty())
                        printf("Answer = %d\n", pop());
                    break;
                case ' '  :
                case '\t' : 
                    break;
                default   : 
                    printf("不正な入力がありました。\n");
                    printf("入力し直してください。\n");
                    while((character = getchar()) != EOF); 
                    break;
            }
        }
    }

    return 0;
}

/*

1 2 + 3 4 - *

*/
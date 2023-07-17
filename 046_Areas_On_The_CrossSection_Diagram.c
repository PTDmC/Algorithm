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
        printf("Stack is full!");
    }
}

char pop(){
    if(stack_pointer <= 0){
        printf("Stack is empty!");
        return -1;
    }
    return Stack[--stack_pointer];                  //[--x] と [x--] の二通りがある
}

int main(){
    int count = 0, sum = 0; 
    char character;

    while((character = getchar()) != EOF){
        switch(character){
            case '\\'  : 
                push(count);
                break;
            case '/'  : 
                if(is_Empty()) sum += count - pop();
                else           sum += count;
                count = 0;
                printf("sum : %d\n", sum);
                break;
            case '_'  :
                break;
            case '\t' :
            case ' '  :
                break;
            case '\n' :
                if(!is_Empty()) printf("%d\n", sum);
                goto End;
            default   : 
                printf("不正な入力がありました。\n");
                printf("入力し直してください。\n");
                while((character = getchar()) != EOF); 
                break;
        }
        count++;
    }

    End : 
    return 0;
}

/*

\\///\_/\/\\\\/_/\\///__\\\_\\/_\/_/\

*/
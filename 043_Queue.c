#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100000
#define QUEUE_SIZE 100

struct array{
    char name[10];
    long num;
};

struct array Queue[QUEUE_SIZE];
int head = 0;
int tail = 0;

int is_Empty(){
    return head == tail;
}

void enqueue(struct array x){
    if(head - 1 != tail){
        Queue[(tail++ % QUEUE_SIZE)] = x;              // tail = (tail + 1) % QUEUE_SIZE
    }
    else{
        printf("Queue is full!");
    }
}

struct array dequeue(){
    if(head == tail){
        printf("Queue is empty!");
        struct array n = {"None", 0};
        return n;
    }
    return Queue[(head++ % QUEUE_SIZE)];               // head = (head + 1) % QUEUE_SIZE
}

int main(){

    int i, n;
    long cost, sum = 0;

    struct array X[100];

    scanf_s("%d %ld", &n, &cost);
    for(i = 0; i < n; i++){
        scanf_s("%s %ld", X[i].name, &X[i].num);
        enqueue(X[i]);
    }

    puts("");

    while(!is_Empty()){
        struct array A = dequeue();

        long diff = A.num - cost;

        sum += (diff > 0) ? cost : A.num;
        A.num = (diff > 0) ? A.num - cost : 0;
        
        if(A.num != 0) enqueue(A);
        else{
            printf("%s %ld\n", A.name, sum);
        }
    }

    return 0;
}

/*

5 100
p1 150
p2 80
p3 200
p4 350
p5 20

*/
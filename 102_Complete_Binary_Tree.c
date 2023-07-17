#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100001

int move_parent(int current) {return current / 2;}
int move_left  (int current) {return current * 2;}
int move_right (int current) {return current * 2 + 1;}

int main(){
    int n, i, Heap[N + 1];                  // 1オリジンにする(添え字 0 は使わない)

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 1; i <= n; i++){
        scanf_s("%d", &Heap[i]);
    }

    for(i = 1; i <= n; i++){
        printf("Node %d : key = %d, ", Heap[i], i);
        if(move_parent(i) >= 1) printf("parent key = %d, ", Heap[move_parent(i)]);
        if(move_left  (i) <= n) printf("left key = %d, "  , Heap[move_left(i)]);
        if(move_right (i) <= n) printf("right key = %d, " , Heap[move_right(i)]);
        puts("");
    }
    
    return 0;
}

/*

5
7 8 1 2 3

*/
#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200000
#define swap(x, y) {int tmp = x; x = y; y = tmp;}

void print_array(int A[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    puts("");
}

// i回のループがi回行われるので、計算量は NC2 = 1 + 2 + 3 + ... + N-1 + N = N(N-1)/2

int swap_cnt = 0;

void Bubble_Sort(int A[], int n){

    int i, j, flag;

    for(i = n - 1; flag; i--){          // 外部のループは逆向き！
        flag = 0;
        for(j = 1; j <= i; j++){
            if(A[j - 1] > A[j]){
                swap(A[j - 1], A[j]);
                flag = 1;
                swap_cnt++;
            }            
        }
    }
}    

int main(){
    int n, i;
    int A[N];

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%d", &A[i]);
    }
    puts("");

    Bubble_Sort(A, n);
    print_array(A, n);
    printf("%d\n", swap_cnt);

    return 0;
}

/*

5
5 3 2 4 1

*/
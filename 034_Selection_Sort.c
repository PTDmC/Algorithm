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

void Selection_Sort(int A[], int n){

    int i, j, buff, min;

    for(i = 0; i < n; i++){
        min = i;                    // i以降の最小の値の添え字を格納
        for(j = i; j < n; j++){
            if(A[min] > A[j]){      // 最小の値を格納する添え字を更新
                min = j;
            }            
        }
        if(i != min){
            swap(A[i], A[min]);     // i番目の値とその後ろの最小の値を交換
            swap_cnt++;
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

    Selection_Sort(A, n);
    print_array(A, n);
    printf("%d\n", swap_cnt);

    return 0;
}

/*

6
5 6 4 2 1 3

*/
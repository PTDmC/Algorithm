#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 10001
#define INFTY 1 << 21;

// 配列の要素数をn、要素の最大値をkとすると、計算量はO(n + k)

int cnt = 0;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void Counting_Sort(int A[], int n){

    int Cumulative_Sum[N] = {};
    int i, max = -1;
    int *Buff;

    Buff = (int *)malloc(sizeof(int) * n + 1);

    for(i = 0; i < n; i++){
        Cumulative_Sum[A[i]]++;
        Buff[i] = A[i];
        max = (Buff[i] > max) ? Buff[i] : max;
        cnt++;
    }

    for(i = 1; i < max + 1; i++){
        Cumulative_Sum[i] += Cumulative_Sum[i - 1];         // 累積和を計算 - 計算量はO(k)
        cnt++;
    }

    for(i = n - 1; i >= 0; i--){
        A[--Cumulative_Sum[Buff[i]]] = Buff[i];
        cnt++;
    }

}

int main(){
    int A[N], n, i; 

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%d", &A[i]);
    }

    Counting_Sort(A, n);

    for(i = 0; i < n; i++){
        printf("%d", A[i]);
        printf(" ");
    }
    puts("");
    printf("Count : %d\n", cnt);

    return 0;
}

/*

100
37 22 97 54 21 12 48 26 53 94 57 19 75 15 64 47 46 60 40 90 8 72 68 79 58 24 33 14 69 86 11 81 0 39 93 56 88 6 3 28 23 51 29 67 71 18 96 92 52 1 87 84 13 30 83 59 25 91 5 43 66 41 16 95 4 82 89 17 35 44 63 74 65 98 99 77 20 100 7 80 34 2 45 9 78 42 49 70 61 36 55 62 31 38 32 85 10 73 76 27

10
2 6 8 4 9 7 5 1 0 10

*/
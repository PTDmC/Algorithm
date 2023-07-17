#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 10001
int cnt = 0;

int bit[N];

// 全列挙のパターンだけ関数が実行されるので、計算量はO(2^n)


int Ex_Search(int A[], int n, int Q){

    int bit, i;
    for(bit = 0; bit < (1 << n); bit++){
        int Sum = 0;
        for (int i = 0; i < n && Sum <= Q; i++) {
            cnt++;
            if (bit & (1 << i)) { 
                Sum += A[i];
            }
            if(Sum == Q) return 1;
        }
    }
    return 0;
}

int main(){

    int A[N], Q, q, n, i; 

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%d", &A[i]);
    }

    printf("Q : ");
    scanf_s("%d", &q);
    for(i = 0; i < q; i++){
        scanf_s("%d", &Q);     
        if(Ex_Search(A, n, Q)) printf("Yes\n");
        else                         printf("No\n");
        printf("Count : %d\n", cnt);
    }



    return 0;
}

/*

5
1 5 7 10 21
4
2 4 17 8

*/
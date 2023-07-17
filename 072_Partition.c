#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 10001
#define INFTY 1 << 21;

// 計算量はO(n)

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int A[], int Part, int R){

    int basis = A[R - 1];                  // 一番後ろの要素を基準にする
    int i = Part - 1;                      // 探索範囲の1つ後ろ(-1)から
    int j;

    for(j = Part; j < R - 1; j++){         // basisに指定した一番後ろの要素は範囲外とする
        if(A[j] <= basis){                 // basis以下だった要素を前から順に詰めていく(元の要素と置き換え)
            i++;                           // iを進めてから
            swap(&A[i], &A[j]);       // 詰める場所の添え字はiによって指定する
                                           // したがって、iは最後に詰めた位置を指す
        }
    }
    swap(&A[i + 1], &A[R - 1]);       // iの1つ後ろが基準との境界になるようにする
    return i + 1;                          // 基準との境界の添え字を返す
}

int main(){
    int A[N], n, i; 

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%d", &A[i]);
    }

    int P = Partition(A, 0, n);
    puts("");

    for(i = 0; i < n; i++){
        if(i == P) printf("[");
        printf("%d", A[i]);
        if(i == P) printf("]");
        printf(" ");

    }


    return 0;
}

/*

100
37 22 97 54 21 12 48 26 53 94 57 19 75 15 64 47 46 60 40 90 8 72 68 79 58 24 33 14 69 86 11 81 0 39 93 56 88 6 3 28 23 51 29 67 71 18 96 92 52 1 87 84 13 30 83 59 25 91 5 43 66 41 16 95 4 82 89 17 35 44 63 74 65 98 99 77 20 100 7 80 34 2 45 9 78 42 49 70 61 36 55 62 31 38 32 85 10 73 76 27

10
2 6 8 4 9 7 5 1 0 3

*/
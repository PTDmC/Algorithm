#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 関数の階層 k-1階層 から k階層 に下がると、実行回数が 2^k 回増える。
// よって、関数の実行回数は 
//           2^0 + 2^1 + 2^2 + ... + 2^k = Σ[i=0, k] 2^i 
//                                       = (2^(k + 1) - 1) / (2 - 1) 
//                                       = 2^(k + 1) - 1 
//                                                               である。
// 深さk = logN なので、Nの式に直すと 2^(k + 1) - 1 = 2^(log N + 1) - 1 = 2 * N - 1  よって計算量は O(N)


#define N 10001
int cnt = 0;

int FindMaximum(int A[], int L, int R){
    cnt++;

    int x, u, v;
    int mid = (L + R) / 2;
    if(L == R - 1) return A[L];
    else {
        u = FindMaximum(A, mid, R);     // 探索と違い、範囲を絞るのではなく要素を分割する。
        v = FindMaximum(A, L, mid);
        x = (u > v) ? u : v;
    }

    return x;
}

int main(){

    int A[N], n, i; 

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%d", &A[i]);
    }

    printf("Max : %d\n", FindMaximum(A, 0, n));
    printf("Count : %d\n", cnt);
    return 0;
}

/*

16
0 1 2 3 4 5 6 7 8 9 10 11 15 14 13 12 

100
51 3 1 87 12 22 6 36 30 2 91 93 73 34 20 39 76 62 21 27 0 52 64 47 69 72 28 68 84 89 16 79 25 29 4 49 18 77 96 41 23 15 43 55 31 63 100 14 40 45 94 60 44 65 71 82 90 54 59 37 88 26 9 80 66 95 17 74 10 24 13 50 61 11 38 32 35 46 19 56 67 5 81 53 42 70 58 57 85 33 92 75 83 48 86 7 78 98 99 8

*/
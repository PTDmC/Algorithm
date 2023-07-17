#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 10001
#define INFTY 1 << 21;

// Mergeの総計算量はO(n), Merge_Sortの実行回数は logn なので、総計算量は O(nlogn)

int cnt = 0;

void Merge(int A[], int L, int mid, int R){
    int Size_1 = mid - L;                       // mid は範囲に含まれないので、 mid - L + 1 としなくて良い
    int Size_2 = R - mid;  

    int Left[N], Right[N], i, j, k;

    for(i = 0; i < Size_1; i++){
        Left[i] = A[L + i];                     // 範囲は L からであることに注意
    }
    for(i = 0; i < Size_2; i++){
        Right[i] = A[mid + i];
    }
    Left[Size_1] = INFTY;
    Right[Size_2] = INFTY;
    
    i = j = 0;
    for(k = L; k < R; k++){
        cnt++;
        if(Left[i] <= Right[j]) A[k] = Left[i++];                // <= とすることで、順序が保たれる
        else                    A[k] = Right[j++];
    }
}

void Merge_Sort(int A[], int L, int R){

    if(L + 1 < R){                  // 分割の際に L + 1 としない代わりに終了条件を L + 1 にする。
        int mid = (L + R) / 2;
        Merge_Sort(A, L, mid);   // 探索ではないので L + 1 のようにして要素を除外してはいけない
        Merge_Sort(A, mid, R);
        Merge(A, L, mid, R);
    }
    return;
}

int main(){
    int A[N], n, i; 

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%d", &A[i]);
    }

    Merge_Sort(A, 0, n);
    puts("");

    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    puts("");
    printf("%d\n", cnt);

    return 0;
}

/*

100
37 22 97 54 21 12 48 26 53 94 57 19 75 15 64 47 46 60 40 90 8 72 68 79 58 24 33 14 69 86 11 81 0 39 93 56 88 6 3 28 23 51 29 67 71 18 96 92 52 1 87 84 13 30 83 59 25 91 5 43 66 41 16 95 4 82 89 17 35 44 63 74 65 98 99 77 20 100 7 80 34 2 45 9 78 42 49 70 61 36 55 62 31 38 32 85 10 73 76 27

10
2 6 8 4 9 7 5 1 0 3

*/
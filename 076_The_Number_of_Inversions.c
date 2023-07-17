#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 10001
#define INFTY 1 << 21;

// Mergeの総計算量はO(n), Merge_Sortの実行回数は logn なので、総計算量は O(nlogn)

int Merge(int A[], int L, int mid, int R){
    int Size_1 = mid - L;                               // mid は範囲に含まれないので、 mid - L + 1 としなくて良い
    int Size_2 = R - mid;  

    int Inverse_cnt = 0;                                // この分割範囲内に存在する反転数

    int Left[N], Right[N], i, j, k;

    for(i = 0; i < Size_1; i++){
        Left[i] = A[L + i];                             // 範囲は L からであることに注意
    }
    for(i = 0; i < Size_2; i++){
        Right[i] = A[mid + i];
    }
    Left[Size_1] = INFTY;
    Right[Size_2] = INFTY;
    
    i = j = 0;
    for(k = L; k < R; k++){
        if(Left[i] <= Right[j]) A[k] = Left[i++];        // <= とすることで、順序が保たれる
        else {
           A[k] = Right[j++];
           Inverse_cnt += Size_1 - i;           
           // 右の配列の値の方が小さかったとき、その後ろに挿入される左の配列の値は、その値より大きいので、元々の位置を考えると反転していたと考えられる。
        }
    }
    return Inverse_cnt;
}

int Merge_Sort(int A[], int L, int R){

    if(L + 1 < R){                              // 分割の際に L + 1 としない代わりに終了条件を L + 1 にする。
        int mid = (L + R) / 2;
        int cnt_1 = Merge_Sort(A, L, mid);   // 探索ではないので L + 1 のようにして要素を除外してはいけない
        int cnt_2 = Merge_Sort(A, mid, R);
        int cnt_3 = Merge(A, L, mid, R);
        return cnt_1 + cnt_2 + cnt_3;
    }
    else return 0;
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

    printf("%d\n", Merge_Sort(A, 0, n));

    return 0;
}

/*

5
3 5 2 1 4

*/
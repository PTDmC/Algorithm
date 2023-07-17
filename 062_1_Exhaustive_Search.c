#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 10001
int cnt = 0;

// 全列挙のパターンだけ関数が実行されるので、計算量はO(2^n)


int Ex_Search(int A[], int n, int Q, int i){
    cnt++;

    if(Q == 0) return 1;                        // Q がピッタリ0になれば1を返す
    if(i >= n) return 0;                        // A の要素を全て選んでしまったら0を返す

    // A[i]を引く場合と引かない場合で分岐させる。どちらかで見つかれば1を返す。
    int res = Ex_Search(A, n, Q, i + 1) || Ex_Search(A, n, Q - A[i], i + 1);

    return res;
}

int main(){

    int A[N], Q, q, n, i; 

    printf("N : ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    printf("Q : ");
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        cnt = 0;
        scanf("%d", &Q);     
        if(Ex_Search(A, n, Q, 0)) printf("Yes\n");
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
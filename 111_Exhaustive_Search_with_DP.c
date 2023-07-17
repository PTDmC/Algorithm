#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INFTY (1 << 21)
#define N 10001
int cnt = 0;

int dp[N][N];  // 本来は n x Q だけ配列を確保できれば良いので、空間計算量は O(nQ)

// 配列を埋める間だけ関数が実行されるので、計算量は O(nQ)

int Ex_Search(int A[], int n, int Q, int i){
    cnt++;

    // dp[i][Q] が 「 Q の値から A[i] を引く 」という1つのパターンに該当する

    if(dp[i][Q] != -INFTY) 
        return dp[i][Q];                            // 計算済みである場合returnする

    if(Q == 0)
        dp[i][Q] = 1;                               // Q がピッタリ0になれば1を返す

    else if(i >= n) 
        dp[i][Q] = 0;                               // A の要素を全て選んでしまったら0を返す

    else if(Ex_Search(A, n, Q, i + 1))           
        dp[i][Q] = 1;                               // A[i] を引く場合で成功した場合 1 が伝播してくるので、1を代入する

    else if(Ex_Search(A, n, Q - A[i], i + 1))  
        dp[i][Q] = 1;                               // A[i] を引かない場合で成功した場合 1 が伝播してくるので、1を代入する
        
    else    
        dp[i][Q] = 0;

    return dp[i][Q];
}

int main(){

    int A[N], Q, q, n, i, j; 

    printf("N : ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    printf("Q : ");
    scanf("%d", &q);

    for(i = 0; i < n + 1; i++){
        for(j = 0; j < N; j++){
            dp[i][j] = -INFTY;
        }
    }


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

15
2 1 5 7 10 21 9 8 7 3 12 65 10 11 31
4
2 4 17 8

*/
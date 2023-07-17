#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INFTY (1 << 21)
#define N 10001
int cnt = 0;

int dp[N];

// 配列を埋める間だけ関数が実行されるので、計算量は O(n)

// メモ化再帰は動的計画法に比べ、関数呼び出し(+即return)によるオーバーヘッドがあるため、定数倍の計算量がかかる (2倍くらい)
int Fibonacci_memo(int n){
    cnt++;

    if(n == 1 || n == 0) return dp[n] = 1;

    if(dp[n] != -INFTY) 
        return dp[n];                            // 計算済みである場合returnする

    return dp[n] = Fibonacci_memo(n - 1) + Fibonacci_memo(n - 2); 
}

// メモ化再帰をループに展開したアルゴリズムを動的計画法という
// メモ化再帰とは異なり、こちらは添え字の小さい方から求めていく
int Fibonacci_DP(int n){
    cnt++;
    int i;

    dp[0] = 1;
    dp[1] = 1;

    for(i = 2; i <= n; i++){
        cnt++;
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n]; 
}

int main(){

    int n, i; 

    printf("N : ");
    scanf("%d", &n);

    for(i = 0; i < n + 1; i++){
        dp[i] = -INFTY;
    }

    printf("%d   ", Fibonacci_memo(n));
    printf("Cnt : %d\n" ,cnt);

    for(i = 0; i < n + 1; i++){
        dp[i] = -INFTY;
    }
    cnt = 0;

    printf("%d   ", Fibonacci_DP(n));
    printf("Cnt : %d\n" ,cnt);

    return 0;
}

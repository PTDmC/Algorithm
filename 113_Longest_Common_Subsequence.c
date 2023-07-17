#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INFTY (1 << 21)
#define N 10001
int cnt = 0;

int dp[N][N];

// dp[i][j] : Aのi文字目かつ、Bのj文字目までのLCSの長さを格納している 

// 配列を埋める間だけ関数が実行されるので、計算量は O(strlen(A)*strlen(B))

int LCS(char A[], char B[]){
    cnt = 0;
    int i, j;

    for(i = strlen(A); i >= 1 ; i--){       // 1オリジンにするため、先頭に空白を挿入
        A[i] = A[i - 1];
    }
    A[0] = ' ';

    for(i = strlen(B); i >= 1 ; i--){
        B[i] = B[i - 1];
    }
    B[0] = ' ';

    for(i = 1; i < strlen(A); i++){
        for(j = 1; j < strlen(B); j++){
            cnt++;
            if(A[i] == B[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;        
                // Aのi-1文字目かつBのj-1文字目までのLCSの長さ(つまりそれぞれの注目文字位置以前のLCSの長さ)に +1 する         
            }
            else dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);  
            // Aのi-1文字目かつBのj文字目まで、または、Aのi文字目かつBのj-1文字目までのLCSの長さのうち、長い方を継承する
        }   
    }


    puts("");
    for(i = 0; i < strlen(A); i++){
        for(j = 0; j < strlen(B) ; j++){
            if(i > 0 && j > 0) printf("%d ", dp[i][j]);
            else if(j == 0 && i > 0) printf("%c ", A[i]);
            else if(i == 0 && j > 0) printf("%c ", B[j]);
            else printf("  ");
        }   
        puts("");
    }
    puts("");

    return dp[strlen(A) - 1][strlen(B) - 1]; 
}

int main(){

    int n, i, j, k; 
    char A[N], B[N];

    printf("N : ");
    scanf("%d", &n);
    
    for(k = 0; k < n; k++){
        printf("A : ");
        scanf("%s", A);
        printf("B : ");
        scanf("%s", B);

        for(i = 0; i <= strlen(A); i++){
            for(j = 0; j <= strlen(B); j++){
                dp[i][i] = 0;
            }
        }
    
        printf("%d   ", LCS(A, B));
        printf("Cnt : %d\n" ,cnt);
    }


    return 0;
}
/*

1
abcbdab
bdcada

3
abcbdab
bdcada
abc
abc
abc
bc

*/
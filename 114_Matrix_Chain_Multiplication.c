#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INFTY (1 << 25)
#define N 10001
int cnt = 0;

// 最初の行列の(タテの長さ)×(ヨコの長さ) に 次にかける行列の(ヨコの長さ)をかけ合わせていくことで行列の要素の総乗算回数が求まる。

int dp[N + 1][N + 1];

void print(int n){
    int i, j;
    puts("");
    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++)
            if(j > 0 && i > 0) printf("%8d        ",dp[i][j]);
            else if(i == 0 && j > 0) printf("M[%d]            ",j);
            else if(i > 0 && j == 0) printf("M[%d]        ",i);
            else printf("                ");
        puts("");
    }
}

int main(){

    int n, matrix[N + 1];

    printf("N : ");
    scanf("%d", &n); // 掛ける行列の数

    int i;
    for(i = 1; i <= n; i++){
        printf("M[%d] : ",i);
        scanf("%d %d", &matrix[i-1], &matrix[i]);
    }
    // 各行列のタテの長さとヨコの長さを入力する。
    // ここで、前の行列のヨコの長さと、次の行列のタテの長さは一致する必要がある。
    // 一致している部分は実際の配列内では省略しているが、上では入力状況が分かりやすいようにわざと重複入力にしている。(やる必要はない)
    
    for(i = 1; i <= n; i++){    // 対角成分を全て0にする
        dp[i][i] = 0;           // dpで使う領域は上三角部分だけ (行列の順序は変えられないため)
    }

    int k, l;
    for(k = 2; k <= n; k++){
        for(i = 1; i <= n - k + 1; i++){        // i, j は 二次元配列の上三角部分を右下方向に走査する　
            int j = i + k - 1;                  // 例) 4x4の場合  (1, 2)→(2, 3)→(3, 4) → (1, 3)→(2, 4) → (1, 4)
            dp[i][j] = INFTY;                   // 上三角全てをINFTYで初期化

            // dp[i][j] は M[i]*...*M[j]を計算するための最小の乗算回数

            for(l = i; l < j; l++){   // l (i <= l < j) は M[i]*...M[j-1] の 選び方のパターンを全て走査する

                int max = dp[i][l] + dp[l + 1][j] + matrix[i - 1] * matrix[l] * matrix[j];
                //  max = ( 乗算コストのパターン ) + ( M[i-1]*...*M[l] までの乗算回数に M[j] を乗算したときの回数)

                dp[i][j] = fmin(dp[i][j], max);
                // 一回目のループではdp[i][j]はINFTYなので max の値を直接代入
                // それ以降のループでは
                
                printf("\n dp[%d][%d] = dp[%d][%d] + dp[%d][%d] + p[%d] x p[%d] x p[%d]\n", i, j, i, l, l+1, j, i-1, l, j);
                print(n);
            }
        }
    }

    printf("%d\n", dp[1][n]);

    return 0;
}

/*

5
1 2
2 3
3 4
4 5
5 6

6
30 35
35 15
15 5
5 10
10 20
20 25

*/
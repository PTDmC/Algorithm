#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200000

int main(){
    int n, i;
    int R[N];

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%d", &R[i]);
    }

    int min_fx = R[0];                                                             // 最初はR[0]を基準に比較を行う
    int max_profit = -(1 << 21);

    for(i = 1; i < n; i++){
        // ここに入力を組み込めば配列用のメモリを節約できる！
        max_profit = (R[i] - min_fx > max_profit) ? R[i] - min_fx : max_profit;    // 最小値より後ろで最も利益が大きくなる時の値を求める
        min_fx = (R[i] < min_fx) ? R[i] : min_fx;                                  // 最小値を求める
    }

    puts("");
    printf("%d", max_profit);

    return 0;
}



/*

6
5
3
1
3
4
3

3
4
3
2

*/
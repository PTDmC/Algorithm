#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100001

// Check iが品物の個数を超えた時点でreturnされる。また k < n であるため計算量はO(n)
// AllocationのループはO(logP)なので、総合計算量はO(nlogP)

int Check(long long P, int n, int k, long long W[]){

    int i = 0, j;

    for(j = 0; j < k; j++){         // トラック
        long long sum = 0;
        while(sum + W[i] <= P){     // W[]の前からの積和がトラック一台当たりの最小積載量Pを超えるまで
            sum += W[i];
            i++;
            if(i == n) return n;    // 積める荷物が無くなった場合
        }
    }
    return i;
}

long long Allocation(int n, int k, long long W[]){

    int L = 0, R = N * 10000; 

    while(L < R){
        int mid = (L + R) / 2;
        int count = Check(mid, n, k, W);    // 最大積載量P(==mid)のk台トラック全体に積められる荷物の個数
        printf("%d\n", mid);

        if(count >= n) R = mid;               // 積められた個数がnを越えたらPの上限を下げて再度実行する
        else           L = mid + 1;           // 逆に超えなかったら下限を上げる
    }                                         // 以上を繰り返すことで、最適なPを絞っていく
                                              // 下限が最適なPを超えることは無い    

    return R;
}

int main(){
    int n, k, i;
    long long W[N]; 

    printf("N : ");
    scanf_s("%d %d", &n, &k);             // n個の荷物をk台のトラックに積む。
    for(i = 0; i < n; i++){
        scanf_s("%lld", &W[i]);
    }

    printf("%lld\n", Allocation(n, k, W));

    return 0;
}

/*

5 3
8
1
7
3
9

*/
#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// f(N) ~ f(1) までの N-1+1 = N 回だけ関数が実行されるので、計算量は O(N)

int Factorial(int N){
    if(N == 1) return 1;
    return N * Factorial(N - 1);
}

int main(){

    int N;
    scanf_s("%d", &N);

    printf("%d\n", Factorial(N));
    return 0;
}
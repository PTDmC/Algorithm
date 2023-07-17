#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// f(N) ~ f(1) までの N-1+1 = N 回だけ関数が実行されるので、計算量は O(N)

int Fibonacci(int N){
    if(N == 0 || N == 1) return 1;
    return Fibonacci(N - 1) + Fibonacci(N - 2);
}

int main(){
    int N;
    printf("Num : ");
    scanf("%d", &N);

    printf("%d\n", Fibonacci(N));
    return 0;
}
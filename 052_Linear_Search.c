#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 10001

int Linear_Search(int S[], int key, int n){

    int i = 0;
    S[n] = key;                       // S[n] に達したときに終了するための条件を付ける
    while(S[i] != key) i++;

    return i != n;                    // S[n] に達した場合は弾く
}

int main(){
    int S[N], T, n, q, C = 0, i; 

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%d", &S[i]);
    }

    printf("N : ");
    scanf_s("%d", &q);
    for(i = 0; i < q; i++){
        scanf_s("%d", &T);
        if(Linear_Search(S, T, n)) C++;
    }
    puts("");

    printf("%d\n", C);

    return 0;
}

/*

5
1 2 3 4 5
3
3 4 1

10
9 8 7 6 5 4 3 2 5 1
5
7 7 9 6 5

*/
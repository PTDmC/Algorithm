#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 10001

int Binary_Search(int S[], int key, int n){

    int L = 0, R = n; 

    while(L < R){
        int mid = (L + R) / 2;
        if     (S[mid] == key)   return 1;
        else if(S[mid] < key)    L = mid + 1;
        else if(S[mid] > key)    R = mid;
    }

    return 0;
}

int Binary_Search2(int S[], int key, int L, int R){

    int mid = (L + R) / 2;
    if     (S[mid] == key)   return 1;
    else if(S[mid] < key)    return Binary_Search2(S, key, mid + 1, R) == 1;
    else if(S[mid] > key)    return Binary_Search2(S, key, L, mid)     == 1;

    return 0;
}

int main(){
    int S[N], T, n, q, C = 0, C2 = 0, i; 

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%d", &S[i]);     // データはソート済みである必要あり
    }

    printf("N : ");
    scanf_s("%d", &q);
    for(i = 0; i < q; i++){
        scanf_s("%d", &T);
        if(Binary_Search(S, T, n)) C++;
        if(Binary_Search2(S, T, 0, n)) C2++;
    }
    puts("");

    printf("%d\n", C);
    printf("%d\n", C2);

    return 0;
}

/*

5
1 2 3 4 5
3
3 4 1

10
0 1 2 3 4 5 6 7 8 9
5
0 7 9 6 5

*/
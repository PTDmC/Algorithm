#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INFTY (1 << 25)
#define N 10001
int cnt = 0;

int  M[N][N] = {};

int main(){

    int n, u, k, v;

    printf("N : ");
    scanf("%d", &n);

    int i, j;
    for(i = 0; i < n; i++){
        scanf("%d %d", &u, &k);
        for(j = 0; j < k; j++){
            scanf("%d", &v);
            M[u - 1][v - 1] = 1;
        }
    }

    puts("");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", M[i][j]);
        }
        puts("");
    }

    return 0;
}

/*

4
1 2 2 4
2 1 4
3 0
4 1 3

*/
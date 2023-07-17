#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define MAX 100000
#define NIL -1

///////////////////////////////////////////// 未完成 ////////////////////////////////////////////////////

int Pre[MAX], In[MAX], Post[MAX];
int n, pos;

// 再帰の各階層において、O(n)の探索を行うので、最悪計算量はO(n^2)

void Reconstruction(int L, int R){
    if(L >= R) return;
    int root = Pre[pos++];
    int m;
}

int main(void){
 
    int n, P, L, R, root = 0;
    int i, j;

    printf("N : ");
    scanf_s("%d", &n);

    return 0;
}

/*

5
1 2 3 4 5
3 2 4 1 5

*/
#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2000
#define swap(x, y) {struct array tmp = x; x = y; y = tmp;}

struct array{
    int num;
    char symbol;
};

void print_array(struct array A[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%c%d ", A[i].symbol, A[i].num);
    }
    puts("");
}

// i回のループがi回行われるので、計算量は NC2 = 1 + 2 + 3 + ... + N-1 + N = N(N-1)/2

void is_Stable(struct array A[], struct array B[], int n){
    int i;
    for(i = 0; i < n; i++){
        if(A[i].symbol != B[i].symbol){
            printf("Not Stable");
            return;
        }
    }
    printf("Stable");

}

void Bubble_Sort(struct array A[], int n){

    int i, j, flag;

    for(i = n - 1; flag; i--){          // 外部のループは逆向き！
        flag = 0;
        for(j = 1; j <= i; j++){
            if(A[j - 1].num > A[j].num){
                swap(A[j - 1], A[j]);
                flag = 1;
            }            
        }
    }
}    

void Selection_Sort(struct array A[], int n){

    int i, j, buff, min;

    for(i = 0; i < n; i++){
        min = i;                    // i以降の最小の値の添え字を格納
        for(j = i; j < n; j++){
            if(A[min].num > A[j].num){      // 最小の値を格納する添え字を更新
                min = j;
            }            
        }
        if(i != min){
            swap(A[i], A[min]);     // i番目の値とその後ろの最小の値を交換
        }
    }
}   

int main(){
    int n, i;
    
    struct array A[N], B[N];
    
    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s(" %c %d", &A[i].symbol, &A[i].num);
        B[i] = A[i];
    }
    puts("");

    Bubble_Sort(A, n);
    Selection_Sort(B, n);

    print_array(A, n);
    print_array(B, n);

    is_Stable(A, B, n);
    
    return 0;
}

/*

5
H4 C9 S4 D2 C3

*/
#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200000

void print_array(int A[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    puts("");
}

// i回のループがi回行われるので、計算量は NC2 = 1 + 2 + 3 + ... + N-1 + N = N(N-1)/2

void Insertion_Sort(int A[], int n){

    int i, j, buff;
    for(i = 1; i < n; i++){

        print_array(A, n);

        buff = A[i];                    // A[i]の値を保持
        j = i - 1;                      // iより前を探索範囲とする
        while(A[j] > buff && j >= 0){   
            A[j + 1] = A[j];            // buffより大きい値は今の位置jから1つ後ろのj+1にずらす
            j--;                        // jを一つ前にする
        }
        A[j + 1] = buff;                // whileを抜ける前に余分にj--しているため、配列の隙間はjの1つ後ろ
    }
}    

int main(){
    int n, i;
    int A[N];

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%d", &A[i]);
    }
    puts("");

    Insertion_Sort(A, n);
    print_array(A, n);

    return 0;
}



/*

6
5 2 4 6 1 3

*/
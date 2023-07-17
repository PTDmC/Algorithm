#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200000
#define swap(x, y) {int tmp = x; x = y; y = tmp;}

void print_array(int A[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    puts("");
}

// 形は挿入ソートの配列のずれを1からhに変えただけ
// 計算量は O(N^1.25) ~ O(N^1.5)

void Shell_Sort(int A[], int n){

    int i, j, buff;
    int h;

    for(h = 1; h < n / 9; h = h * 3 + 1);   // h は n/9 以下にする    h[n] = 3*h[n-1] + 1

    for(; h > 0; h /= 3){
        printf("h : %d\n", h);
        for(i = h; i < n; i++){
            
            print_array(A, n);

            buff = A[i];                    // A[i]の値を保持
            j = i - h;                      // iより前を探索範囲とする
            while(A[j] > buff && j >= 0){   
                A[j + h] = A[j];            // buffより大きい値は今の位置jからh後ろのj+hにずらす
                j -= h;                     // jをh前にする
            }
            A[j + h] = buff;                // whileを抜ける前に余分にj-=hしているため、配列の隙間はjのh後ろ
        }
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

    Shell_Sort(A, n);
    print_array(A, n);

    return 0;
}

/*

5
5 1 4 3 2

10
2 5 6 9 7 4 6 3 1 0

100
37 22 97 54 21 12 48 26 53 94 57 19 75 15 64 47 46 60 40 90 8 72 68 79 58 24 33 14 69 86 11 81 0 39 93 56 88 6 3 28 23 51 29 67 71 18 96 92 52 1 87 84 13 30 83 59 25 91 5 43 66 41 16 95 4 82 89 17 35 44 63 74 65 98 99 77 20 100 7 80 34 2 45 9 78 42 49 70 61 36 55 62 31 38 32 85 10 73 76 27

*/
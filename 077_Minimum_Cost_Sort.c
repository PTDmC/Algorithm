#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define N 10001
#define INFTY 1 << 21;
#define false 0
#define true 1

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Partition(int A[], int Part, int R){

    int basis = A[R - 1];                  // 一番後ろの要素を基準にする
    int i = Part - 1;                      // 探索範囲の1つ後ろ(-1)から
    int j;

    for(j = Part; j < R - 1; j++){         // basisに指定した一番後ろの要素は範囲外とする
        if(A[j] <= basis){                 // basis以下だった要素を前から順に詰めていく(元の要素と置き換え)
            i++;                           // iを進めてから
            swap(&A[i], &A[j]);       // 詰める場所の添え字はiによって指定する
                                           // したがって、iは最後に詰めた位置を指す
        }
    }
    swap(&A[i + 1], &A[R - 1]);       // iの1つ後ろが基準との境界になるようにする
    return i + 1;                          // 基準との境界の添え字を返す
}

void Quick_Sort(int A[], int L, int R){
    if(L < R){
        int mid = Partition(A, L, R);
        Quick_Sort(A, L, mid);          // 境界は含めない
        Quick_Sort(A, mid + 1, R);      // 境界は含めない
    }
}

int T[N * 10];

int Minimum_Cost_Sort(int A[], int n, int min_element){
    int Minimum_Cost = 0;
    int i;

    int Buff[N], Link[N] = {false};
    for(i = 0; i < n; i++){
        Buff[i] = A[i];
    }

    Quick_Sort(Buff, 0, n);     // Buffにコピーした配列のみソートする

    for(i = 0; i < n; i++){
        T[Buff[i]] = i;                 // Tの添え字が各要素の現在位置で、i が最終的な移動先
    }
    for(i = 0; i < n; i++){             
        if(Link[i]) continue;           // 既に通ったサイクルなら抜ける
        int current = i;                // 現在位置
        int Sum = 0;
        int min = N;
        int min_move_count = 0;

        while(true){
            Link[current] = true;       // currentはサイクル内を網羅し、それら全てを探索済みとする
            min_move_count++;
            int v = A[current];         // 現在位置のAの要素を取り出す
            min = (v < min) ? v : min;  // サイクル内の最小の重さを求める
            Sum += v;                   // サイクル内の総コストに加える
            current = T[v];             // サイクルを移動
            if(Link[current]) break;    // サイクルを一周したらbreak
        }
        int X = Sum + (min_move_count - 2) * min;               // サイクル内の総コスト
        int Y = min + Sum + (min_move_count + 1) * min_element; // 配列A全体の最小値min_elementを考慮したサイクルの総コスト
        Minimum_Cost += (X < Y) ? X : Y;
    }
    return Minimum_Cost;
}

int main(){
    int n, i, min_element = INFTY;
    int A[N];

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%d", &A[i]);
        min_element = (A[i] < min_element) ? A[i] : min_element;
    }
    puts("");

    printf("%d\n", Minimum_Cost_Sort(A, n, min_element));

    return 0;
}

/*

5
1 5 3 4 2

*/
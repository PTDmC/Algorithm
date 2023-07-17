#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100001

int move_parent(int current) {return current / 2;}
int move_left  (int current) {return current * 2;}
int move_right (int current) {return current * 2 + 1;}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// あるノードから葉まで辺を一本づつ伝って再帰する関数なので、計算量はあるノードの高さに比例し、計算量は平均してO(logn)程度
void max_Heapify(int Heap[], int n, int current){

    int Largest;
    int L = move_left(current);
    int R = move_right(current);

    // current, L, R で最も大きい値を持つ要素の添え字をLargestに格納する
    if(L <= n && Heap[L] > Heap[current]) Largest = L;      
    else                                  Largest = current;
    if(R <= n && Heap[R] > Heap[Largest]) Largest = R;

    // 現在位置の値ををLとRどちらかの大きい方の値と入れ替える、最大値が現在位置の場合は入れ替えしない。
    printf("       %d %d %d \n", Heap[current], Heap[L], Heap[R]);
    printf("index :%d %d %d \n", current, L, R);
    if(Largest != current){
        printf("Swap\n");
        swap(&Heap[current], &Heap[Largest]);
        max_Heapify(Heap, n, Largest);
    }
}

// 1 ~ n のノードの内 、高さが 1 のものは n/2個 、
//                　 　高さが 2 のものは n/4個
//                              ...           　　
//                　 　高さが logn のものは 1 個存在する。
//
// 高さk = max_Heapifyの計算量 であることから、「 Σ{(ある高さk)×(その高さのノードの数n/2^k)} 」が全体の計算量となる。
//
// よって、build_MaxHeapの計算量は Σ[k = 1, logn] n * k / 2^k = n * { 1/2 + 2/4 + 3/8 + ... + (logn)/(2^logn) } ≈ 2n より、O(n) となる。
//                                                                                               
// ※以下のプログラムでは n/2 ~ n のループを除いているが、計算量には考慮していない。
 
void build_MaxHeap(int Heap[], int n){
    int current;
    for(current = n / 2; current >= 1; current--){  // 葉を子に持つ n/2 のノードから上方向に走査開始の基準を移していく
        max_Heapify(Heap, n, current);              // currentは走査を開始するノードの位置を示す
    }
}

int main(){
    int n, i, Heap[N + 1];                  // 1オリジンにする(添え字 0 は使わない)

    printf("N : ");
    scanf_s("%d", &n);
    for(i = 1; i <= n; i++){
        scanf_s("%d", &Heap[i]);
    }

    build_MaxHeap(Heap, n);                 // 子より親の方が大きい値になるようにする (ソートではない！)
    
    for(i = 1; i <= n; i++){
        printf("%d ", Heap[i]);
    }
    puts("");

    return 0;
}

/*

10
4 1 3 2 16 9 10 14 8 7

5
7 8 1 2 3

*/
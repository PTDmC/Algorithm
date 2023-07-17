#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100001

int move_parent(int current) {return current / 2;}
int move_left  (int current) {return current * 2;}
int move_right (int current) {return current * 2 + 1;}

// max_Heapifyの計算量は   O(logn) 
// build_MaxHeapの計算量は O(n)
// Heap_Sortの計算量は     O(nlogn) より、Heap_Sort の計算量が最も支配的であるので全体の計算量は O(nlogn) 

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void max_Heapify(int Heap[], int n, int current){

    int Largest;
    int L = move_left(current);
    int R = move_right(current);

    if(L <= n && Heap[L] > Heap[current]) Largest = L;      
    else                                  Largest = current;
    if(R <= n && Heap[R] > Heap[Largest]) Largest = R;

    if(Largest != current){
        swap(&Heap[current], &Heap[Largest]);
        max_Heapify(Heap, n, Largest);
    }
}

void build_MaxHeap(int Heap[], int n){
    int current;
    for(current = n / 2; current >= 1; current--){  // 葉を子に持つ n/2 のノードから上方向に走査開始の基準を移していく
        max_Heapify(Heap, n, current);              // currentは走査を開始するノードの位置を示す
    }
}

int Heap_ExtractMax(int Heap[], int n, int Heap_Size){
    if(Heap_Size < 1){
        printf("under flow\n");
        return -1;
    }
    int max = Heap[1];                                  // ヒープの最大値(根)を取り出す
    Heap[1] = Heap[Heap_Size];                          // ヒープの末尾の値を根に移す
    Heap_Size--;                                        // ヒープサイズを下げる。(これによって末尾が参照されなくなる)
    max_Heapify(Heap, n, 1);                   // 常に根ノードを走査開始の基準とする
                                                        // max_Heapifyによって常にヒープ内の最大値が根に来る。
    return max;
}


void Heap_Sort(int A[], int Heap[], int n){
    int i, Heap_Size = n;
    for(i = 0; i < n; i++){
        A[i] = Heap_ExtractMax(Heap, n, Heap_Size);
    }
}

int main(){
    int n, i, Heap[N + 1], A[N + 1], Heap_Size;                  // 1オリジンにする(添え字 0 は使わない)

    printf("N : ");
    scanf_s("%d", &n);
    Heap_Size = n;
    for(i = 1; i <= n; i++){
        scanf_s("%d", &Heap[i]);
    }

    build_MaxHeap(Heap, n);                                      // Heap_Sortの前にヒープを作る必要がある
    Heap_Sort(A, Heap, n);                 
    
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
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
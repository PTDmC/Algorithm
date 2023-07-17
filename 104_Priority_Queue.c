#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100001
#define INFTY (1 << 21)

int move_parent(int current) {return current / 2;}
int move_left  (int current) {return current * 2;}
int move_right (int current) {return current * 2 + 1;}

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

int Heap_ExtractMax(int Heap[], int *Heap_Size){
    if(*Heap_Size < 1){
        printf("under flow\n");
        return -1;
    }
    int max = Heap[1];                                  // ヒープの最大値(根)を取り出す
    Heap[1] = Heap[*Heap_Size];                         // ヒープの末尾の値を根に移す
    (*Heap_Size)--;                                     // ヒープサイズを下げる。(これによって末尾が参照されなくなる)
    max_Heapify(Heap, *Heap_Size, 1);        // 常に根ノードを走査開始の基準とする
                                                        // max_Heapifyによって常にヒープ内の最大値が根に来る。
    return max;
}

void increaseKey(int Heap[], int i, int key){
    if(key < Heap[i]) return;                                   // key の大きさが負の無限大である場合returnする
    Heap[i] = key;                                              // とりあえずヒープの末尾に挿入する
    while(i > 1 && Heap[move_parent(i)] < Heap[i]){    // ヒープの条件を満たすまで挿入したノードを上に移動させる
        swap(&Heap[i], &Heap[move_parent(i)]);
        i = move_parent(i);
    }
}

void insert(int Heap[], int *Heap_Size, int key){
    (*Heap_Size)++;                                     // ヒープサイズを上げる
    Heap[*Heap_Size] = -INFTY;                          // ヒープの末尾に負の無限大を挿入 (increaseKey内での判断用)
    increaseKey(Heap, *Heap_Size, key);              // Keyを適切な位置に挿入する
}

int main(){
    int key, Heap[N + 1], Heap_Size = 0;                  // 1オリジンにする(添え字 0 は使わない)
    char com[10];
    int i;

    while(1){
        printf("Command : ");
        scanf("%s", com);
        if(strcmp("end", com) == 0) break;
        if(strcmp("insert", com) == 0){
            scanf("%d", &key);
            insert(Heap, &Heap_Size, key);
        }
        else{
            printf("%d\n", Heap_ExtractMax(Heap, &Heap_Size));
        }

    }

    return 0;
}

/*

insert 8
insert 2
extract
insert 10
extract
insert 11
extract
extract
end

*/
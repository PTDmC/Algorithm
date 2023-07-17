#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

///////////////////////////////////////////// 未完成 ////////////////////////////////////////////////////

#define INFTY (1 << 25)
#define N 10001
#define WHITE 0     // 未訪問
#define GRAY  1     // 訪問中
#define BLACK 2     // 訪問済み
int cnt = 0;

// 最小の重みをもつエッジを見つけるために、n個の各ノードあたり、n回のエッジの調査を行うので 計算量は O(n^2)

// 全体のノードの集合をV、最短経路木に属するノードの集合をS、属さないノードの集合をV-Sとする。

typedef struct array{
    int Node_Num;
    int Cost;
} NODE;

int move_parent(int current) {return current / 2;}
int move_left  (int current) {return current * 2;}
int move_right (int current) {return current * 2 + 1;}

void swap(NODE *a, NODE *b){
    NODE tmp = *a;
    *a = *b;
    *b = tmp;
}

void min_Heapify(NODE Heap[], int n, int current){

    int Smallest;
    int L = move_left(current);
    int R = move_right(current);

    if(L <= n && Heap[L].Cost < Heap[current].Cost)  Smallest = L;      
    else                                             Smallest = current;
    if(R <= n && Heap[R].Cost < Heap[Smallest].Cost) Smallest = R;

    if(Smallest != current){
        swap(&Heap[current], &Heap[Smallest]);
        min_Heapify(Heap, n, Smallest);
    }
}

int Heap_ExtractMin(NODE Heap[], int *Heap_Size){
    if(*Heap_Size < 1){
        printf("under flow\n");
        return -1;
    }
    int Min = Heap[1].Cost;                             // ヒープの最大値(根)を取り出す
    Heap[1] = Heap[*Heap_Size];                         // ヒープの末尾の値を根に移す
    (*Heap_Size)--;                                     // ヒープサイズを下げる。(これによって末尾が参照されなくなる)
    min_Heapify(Heap, *Heap_Size, 1);        // 常に根ノードを走査開始の基準とする
                                                        // max_Heapifyによって常にヒープ内の最大値が根に来る。
    return Min;
}

void increaseKey(NODE Heap[], int i, int key){
    if(key < Heap[i].Cost) return;                                      // key の大きさが負の無限大である場合returnする
    Heap[i].Cost = key;                                                 // とりあえずヒープの末尾に挿入する
    while(i > 1 && Heap[move_parent(i)].Cost > Heap[i].Cost){  // ヒープの条件を満たすまで挿入したノードを上に移動させる
        swap(&Heap[i], &Heap[move_parent(i)]);
        i = move_parent(i);
    }
}

void insert(NODE Heap[], int *Heap_Size, int key){
    (*Heap_Size)++;                                     // ヒープサイズを上げる
    Heap[*Heap_Size].Cost = INFTY;                          // ヒープの末尾に負の無限大を挿入 (increaseKey内での判断用)
    increaseKey(Heap, *Heap_Size, key);              // Keyを適切な位置に挿入する
}

void build_MaxHeap(NODE Heap[], int n){
    int current;
    for(current = n / 2; current >= 1; current--){  // 葉を子に持つ n/2 のノードから上方向に走査開始の基準を移していく
        min_Heapify(Heap, n, current);              // currentは走査を開始するノードの位置を示す
    }
}

int M[N][N] = {};
int Color[N]; 
int Heap_Size;    // 始点からこのノードへの最小経路を通った場合の、重みの合計　
                        // 例) Minimum_Cost[i] は ノード0 から重みの最小経路を通って ノードi まで辿った時の重みの合計を格納する

 

NODE Minimum_Cost_Heap[N];

void Dijkstra(int n){
    
    int Current_Node, Min_Dest_Node, i;
    int Min_Cost;

    for(Current_Node = 0; Current_Node < n; Current_Node++){
        Minimum_Cost_Heap[Current_Node].Cost = INFTY;
        Color[Current_Node] = WHITE;                                        // 初期化
    }

    insert(Minimum_Cost_Heap, &Heap_Size, 0);           // 最初はまだ最小エッジを見つけてないので、とりあえず最小のエッジの重さを持っているものとして、重みを0にする
    Color[0] = GRAY;                                                        // 始点ノードを訪問中にする

    //build_MaxHeap(Minimum_Cost_Heap, n);

    while(Heap_Size != 0){
        int Current_Node = Minimum_Cost_Heap[0].Cost;

        if(Minimum_Cost_Heap[Current_Node].Cost < -1) break;                                       // 全てのノードを訪問し、最小経路がこれ以上見つからなかったらbreak

        Color[Current_Node] = BLACK;                                        // 移った先のノードを訪問済みにする　(最初は始点ノードが選ばれる)

        for(Min_Dest_Node = 0; Min_Dest_Node < n; Min_Dest_Node++){
            if(Color[Min_Dest_Node] != BLACK && M[Current_Node][Min_Dest_Node] != -1){                                      // 行先ノードが訪問済みでないかつ、現在のノードと行先ノード間にエッジが存在する場合
                if(M[Current_Node][Min_Dest_Node] < Minimum_Cost_Heap[Min_Dest_Node].Cost){                                      //「現在のノードから行先ノードへ移動した時点での重みの合計」が、「行先ノードが保持している重みの合計」よりも小さかった場合
                    Minimum_Cost_Heap[Min_Dest_Node].Cost = Minimum_Cost_Heap[Current_Node].Cost + M[Current_Node][Min_Dest_Node];    // 行先ノードが保持する重みの合計を上書きする
                    Color[Min_Dest_Node] = GRAY;                                                                            // 行先ノードを訪問中とする (訪問は幅優先)
                }
            }
        }

        min_Heapify(Minimum_Cost_Heap, n, Min_Dest_Node);
    }

    for(Current_Node = 0; Current_Node < n; Current_Node++){
        printf("%d %d\n", Current_Node + 1, (Minimum_Cost_Heap[Current_Node].Cost == INFTY) ? (-1) : Minimum_Cost_Heap[Current_Node].Cost);
    }
}

int main(){

    int n, v;

    printf("N : ");
    scanf("%d", &n);

    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &v);
            M[i][j] = v;
        }
    }

    Dijkstra(n);

    return 0;
}

/*

5
0 3 2 3 3 1 1 2
1 2 0 2 3 4
2 3 0 3 3 1 4 1
3 4 2 1 0 1 1 4 4 3
4 2 2 1 3 3

*/
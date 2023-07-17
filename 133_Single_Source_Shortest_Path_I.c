#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INFTY (1 << 25)
#define N 10001
#define WHITE 0     // 未訪問
#define GRAY  1     // 訪問中
#define BLACK 2     // 訪問済み
int cnt = 0;

// 最小の重みをもつエッジを見つけるために、n個の各ノードあたり、n回のエッジの調査を行うので 計算量は O(n^2) 
// この計算量はグラフのモデルを隣接リストにしても変わらない

// 全体のノードの集合をV、最短経路木に属するノードの集合をS、属さないノードの集合をV-Sとする。

int M[N][N] = {};
int Color[N]; 
int Minimum_Cost[N];    // 始点からこのノードへの最小経路を通った場合の、重みの合計　
                        // 例) Minimum_Cost[i] は ノード0 から重みの最小経路を通って ノードi まで辿った時の重みの合計を格納する

void Dijkstra(int n){
    
    int Current_Node, Min_Dest_Node, i;
    int Min_Cost;

    for(Current_Node = 0; Current_Node < n; Current_Node++){
        Minimum_Cost[Current_Node] = INFTY;
        Color[Current_Node] = WHITE;                                    // 初期化
    }

    Minimum_Cost[0] = 0;                                                // 最初はまだ最小エッジを見つけてないので、とりあえず最小のエッジの重さを持っているものとして、重みを0にする
    Color[0] = GRAY;                                                    // 始点ノードを訪問中にする

    while(1){
        Min_Cost = INFTY;
        int Current_Node = -1;

        for(i = 0; i < n; i++){
            if(Color[i] != BLACK && Minimum_Cost[i] < Min_Cost){        // 訪問済みでないかつ、エッジの重みが最小の行先ノードを探す
                Min_Cost = Minimum_Cost[i];
                Current_Node = i;                                       // 最小の重みをもつエッジをたどって現在位置を行先ノードに移す (最初は始点ノードが選ばれる)
            }
        }

        if(Current_Node == -1) break;                                   // 全てのノードを訪問し、最小経路がこれ以上見つからなかったらbreak

        Color[Current_Node] = BLACK;                                    // 移った先のノードを訪問済みにする　(最初は始点ノードが選ばれる)

        for(Min_Dest_Node = 0; Min_Dest_Node < n; Min_Dest_Node++){
            if(Color[Min_Dest_Node] != BLACK && M[Current_Node][Min_Dest_Node] != -1){                              // 行先ノードが訪問済みでないかつ、現在のノードと行先ノード間にエッジが存在する場合
                if(M[Current_Node][Min_Dest_Node] < Minimum_Cost[Min_Dest_Node]){                                   //「現在のノードから行先ノードへ移動した時点での重みの合計」が、「行先ノードが保持している重みの合計」よりも小さかった場合
                    Minimum_Cost[Min_Dest_Node] = Minimum_Cost[Current_Node] + M[Current_Node][Min_Dest_Node];      // 行先ノードが保持する重みの合計を上書きする
                    Color[Min_Dest_Node] = GRAY;                                                                    // 行先ノードを訪問中とする (訪問は幅優先)
                }
            }
        }
    }

    for(Current_Node = 0; Current_Node < n; Current_Node++){
        printf("%d %d\n", Current_Node + 1, (Minimum_Cost[Current_Node] == INFTY) ? (-1) : Minimum_Cost[Current_Node]);
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
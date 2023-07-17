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

// 全体のノードの集合をV、スパニング木に属するノードの集合をT、属さないノードの集合をV-Tとする。

int M[N][N] = {};
int Color[N]; 
int Minimum_Edge_Cost[N];   // T と V-T をつなぐエッジの中で最も小さい重みを持つエッジの重みの値を格納する。　
                            // 例) Minimum_Edge_Cost[i] は ノードi と あるノード間 の最小エッジの重みを格納する

int Parent[N];              // Min_Dest_Node の親ノードを格納 (木なので閉路を持たず、親を定義できる)

int Prim(int n){
    
    int Current_Node, Min_Dest_Node, i;
    
    for(Current_Node = 0; Current_Node < n; Current_Node++){
        Minimum_Edge_Cost[Current_Node] = INFTY;
        Color[Current_Node] = WHITE;                                    // 初期化
        Parent[Current_Node] = -1;
    }

    Minimum_Edge_Cost[0] = 0;                                           // 最初はまだ最小エッジを見つけてないので、とりあえず最小のエッジの重さを持っているものとして、重みを0にする

    while(1){
        int Min_Cost = INFTY;
        for(i = 0; i < n; i++){
            if(Color[i] != BLACK && Minimum_Edge_Cost[i] < Min_Cost){   // 訪問済みでないかつ、エッジの重みが最小の行先ノードを探す
                Min_Cost = Minimum_Edge_Cost[i];
                Current_Node = i;                                       // 最小の重みをもつエッジをたどって現在位置を行先ノードに移す (最初は始点ノードが選ばれる)
            }
        }

        if(Min_Cost == INFTY) break;                                    // 全てのノードを訪問し、最小スパニング木が完成したらbreak

        Color[Current_Node] = BLACK;                                    // 移った先のノードを訪問済みにする　(最初は始点ノードが選ばれる)

        for(Min_Dest_Node = 0; Min_Dest_Node < n; Min_Dest_Node++){
            if(Color[Min_Dest_Node] != BLACK && M[Current_Node][Min_Dest_Node] != -1){      // 行先ノードが訪問済みでないかつ、現在のノードと行先ノード間にエッジが存在する場合
                if(M[Current_Node][Min_Dest_Node] < Minimum_Edge_Cost[Min_Dest_Node]){      //「現在のノードと行先ノード間のエッジの重み」が、「行先ノードがさらに別のノード(暫定の親ノード)間とで保持しているエッジの重み」よりも小さかった場合
                    Minimum_Edge_Cost[Min_Dest_Node] = M[Current_Node][Min_Dest_Node];      // 行先ノードが保持する最小エッジの重みを上書きする
                    Parent[Min_Dest_Node] = Current_Node;                                   // 行先ノードの親として現在ノードを登録
                    Color[Min_Dest_Node] = GRAY;                                            // 行先ノードを訪問中とする (訪問は幅優先)
                }
            }
        }
    }

    int Sum = 0;
    for(i = 0; i < n; i++){
        if(Parent[i] != -1) Sum += M[i][Parent[i]];     // 行先ノード(親ノード)を辿り、重さを足し合わせる
    }

    return Sum;
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

    printf("%d", Prim(n));

    return 0;
}

/*

5
-1 2 3 1 -1
2 -1 -1 4 -1
3 -1 -1 1 1
1 4 1 -1 3
-1 -1 1 3 -1

*/
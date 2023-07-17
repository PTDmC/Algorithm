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

int  M[N][N] = {};

// DFSは可能な限り、ノードを訪問するアルゴリズムのこと。(訪問することが目的)

// あるノードから、各ノードへのエッジが存在するのかを確認するための計算量が1ノード当たり n回 存在する
// これをn個の各ノードで一回ずつ実行するので 計算量は O(n^2)

// ※ 一回ずつなのは、一度訪問したノードは未訪問ではなくなるため再び再帰されることが無いからである。

int Color[N], Discover_Time[N], Finish_Time[N];
int Current_Time;

void DFS_Visit(int Current_Node, int n){

    Color[Current_Node] = GRAY;                         // 訪問中にする
    Discover_Time[Current_Node] = ++Current_Time;       // 初訪問の時間を記録
    
    int Dest_Node;
    for(Dest_Node = 0; Dest_Node < n; Dest_Node++){
        if(M[Current_Node][Dest_Node] == 0) continue;   // Dest_Nodeへのエッジが存在しない場合
        if(Color[Dest_Node] == WHITE){
            DFS_Visit(Dest_Node, n);      // 未訪問のDest_Nodeが存在する限りそのノードへ再帰する
        }
    }
    Color[Current_Node] = BLACK;                        // このノードから探索可能なノードは探索し切ったので訪問済みとする
    Finish_Time[Current_Node] = ++Current_Time;         // その時の時間を記録
}

void DFS(int n){
    
    int Current_Node;
    
    for(Current_Node = 0; Current_Node < n; Current_Node++){
        Color[Current_Node] = WHITE;                                    // 初期化
    }
    Current_Time = 0;                                                   // 時間の初期化

    for(Current_Node = 0; Current_Node < n; Current_Node++){
        if(Color[Current_Node] == WHITE) DFS_Visit(Current_Node, n);    // 未訪問ノードであればそこを探索開始地点とする
    }

    for(Current_Node = 0; Current_Node < n; Current_Node++){
        printf("%d %d %d\n", Current_Node + 1, Discover_Time[Current_Node], Finish_Time[Current_Node]);
    }
}

int main(){

    int n, u, k, v;

    printf("N : ");
    scanf("%d", &n);

    int i, j;
    for(i = 0; i < n; i++){
        scanf("%d %d", &u, &k);
        for(j = 0; j < k; j++){
            scanf("%d", &v);
            M[u - 1][v - 1] = 1;
        }
    }

    puts("");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", M[i][j]);
        }
        puts("");
    }
    puts("");

    DFS(n);

    return 0;
}

/*

6
1 2 2 3
2 2 3 4
3 1 5
4 1 6
5 1 6
6 0

*/
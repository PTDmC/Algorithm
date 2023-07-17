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
#define QUEUE_SIZE 100
int cnt = 0;

int  M[N][N] = {};

// BFSは可能な限り、ノードを訪問するアルゴリズムのこと。(訪問することが目的)

// あるノードから、各ノードへのエッジが存在するのかを確認するための計算量が1ノード当たり n回 存在する
// これをn個の各ノードで一回ずつ実行するので 計算量は O(n^2)

// ※ 一回ずつなのは、一度訪問したノードは未訪問ではなくなるため再び再帰されることが無いからである。

int Distance[N];                                       // 距離で訪問状況を管理する
int Current_Time;

int Queue[QUEUE_SIZE];
int head = 0;
int tail = 0;

int is_Empty(){
    return head == tail;
}

void enqueue(int x){
    if(head - 1 != tail){
        Queue[(tail++ % QUEUE_SIZE)] = x;              // tail = (tail + 1) % QUEUE_SIZE
    }
    else{
        printf("Queue is full!");
    }
}

int dequeue(){
    if(head == tail){
        printf("Queue is empty!");
        return 0;
    }
    return Queue[(head++ % QUEUE_SIZE)];               // head = (head + 1) % QUEUE_SIZE
}

void BFS(int n, int Start_Node){
    
    enqueue(Start_Node);                                             // Start_Node を登録

    int Current_Node;
    for(Current_Node = 0; Current_Node < n; Current_Node++){
        Distance[Current_Node] = INFTY;                                 // 各ノードへの距離をINFTYで初期化
    }

    Distance[Start_Node] = 0;                                           // Start_Node の距離を0にする

    while(!is_Empty()){
        Current_Node = Queue[head];                                     // Queueの先頭を参照する
        dequeue();                                                      // 先頭をQueueから除去する
        
        int Dest_Node;
        for(Dest_Node = 0; Dest_Node < n; Dest_Node++){                 // Current_Node に隣接するノードを全て走査する
            if(M[Current_Node][Dest_Node] == 0) continue;               // エッジが繋がっていなければスキップ
            if(Distance[Dest_Node] != INFTY)    continue;               // 距離が決まっている場合は訪問済みなのでスキップ
            Distance[Dest_Node] = Distance[Current_Node] + 1;           // 隣接するノードへの距離を+1する
            enqueue(Dest_Node);                                      // 隣接するノードをQueueに登録
        }
    }

    for(Current_Node = 0; Current_Node < n; Current_Node++){
        printf("%d %d\n", Current_Node + 1, (Distance[Current_Node] == INFTY) ? (-1) : Distance[Current_Node]);
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

    BFS(n, 0);

    return 0;
}

/*

4
1 2 2 4
2 1 4
3 0
4 1 3

*/
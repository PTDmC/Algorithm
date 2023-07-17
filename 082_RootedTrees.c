#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define MAX 100000
#define NIL -2

struct Node {
    int parent;
    int left;       // leftにはこのノードの最も左の子ノードを格納
    int right;      // rightにはそのノード自身の右の兄弟を格納する (右側の子ノードではないので注意！)
};

struct Node T[MAX];
int D[MAX];

void printChildren(int u){
    int i, c;
    printf("node %d: ", u);                 // 現在参照しているノード
    printf("parent %d, ", T[u].parent);     // そのノードの親
    printf("depth %d, ", D[u]);             // そのノードの深さ

    if(T[u].parent == NIL)    printf("root, ");          // そのノードが根ノードの場合(親が存在しない)
    else if(T[u].left == NIL) printf("leaf, ");          // そのノードが葉ノードの場合(最も左の子ノードが存在しない)
    else                      printf("internal node, "); // そのノードが内部ノードの場合(それ以外)

    printf("[");

    for(i = 0, c = T[u].left; c != NIL; i++, c = T[c].right){   // ノードuの子ノードを左から順に表示する
        if(i) printf(", ");                              // i > 0 のときにカンマを付ける
        printf("%d", c);
    }

    printf("]\n");

}
int cnt = 0;

// 各ノードを1回ずつ探索するのでO(n)のアルゴリズム
void rec(int u, int dep){
    cnt++;
    D[u] = dep;           // Dにはノードuの深さを格納
    if(T[u].right != NIL) rec(T[u].right, dep);         // そのノードの右側のノードには全て同じ深さを格納
    if(T[u].left != NIL)  rec(T[u].left, dep + 1);  // 下に移動するので深さを1つ増やす
}

int main(void){
 
    int n, Node_ID, Child_Size, i, j;
    int child, left, right; // それぞれ、 子ノード、相対的な左のノード、相対的な右のノード を示す

    printf("N : ");
    scanf_s("%d", &n);

    for(i = 0; i < n; i++) {
        T[i].parent = T[i].left = T[i].right = NIL;
    }

    for(i = 0; i < n; i++){
        scanf_s("%d %d", &Node_ID, &Child_Size);        // Node_IDはノードの番号、Child_Sizeはノードが持つ子の数(次数) 
        for(j = 0; j < Child_Size; j++){
            scanf_s("%d", &child);                      // childは一つのノードに格納する子のリストで最も左から右にずれていく
            if(j == 0) T[Node_ID].left = child;                 // 最初だけ、親ノードの最も左の子を設定
            else       T[left].right = child;                   // それ以降は、左側の子ノードにすぐ右の兄弟を設定していく
            left = child;                                       // 相対的な左側の子ノードを示す。これは少しずつ右にずれていく
            T[child].parent = Node_ID;                          // 各子ノードに親を設定(すべての子で共通)
        }
    }
    for(i = 0; i < n; i++){
        if(T[i].parent == NIL) right = i;                       // 根ノード(親がNIL)の添え字を探し、rightに格納
    }

    // 木の深さを求める
    rec(right, 0);  // (根ノードの添え字, 深さ(0から))

    for(i = 0; i < n; i++) printChildren(i);
 
    printf("%d", cnt);
     
    return 0;
}

/*
13
0 3 1 4 10
1 2 2 3
2 0
3 0
4 3 5 6 7
5 0
6 0
7 2 8 9
8 0
9 0
10 2 11 12
11 0
12 0
*/
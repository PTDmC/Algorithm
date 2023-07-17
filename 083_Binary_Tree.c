#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define MAX 100000
#define NIL -1

struct Node {
    int parent;
    int left;   
    int right;      
};

struct Node Binary_Tree[MAX];
int Depth[MAX], Height[MAX];

int getSibling(int current){
    if(Binary_Tree[current].parent == NIL) return NIL;
    if(Binary_Tree[Binary_Tree[current].parent].left  != current && Binary_Tree[Binary_Tree[current].parent].left  != NIL) return Binary_Tree[Binary_Tree[current].parent].left;
    if(Binary_Tree[Binary_Tree[current].parent].right != current && Binary_Tree[Binary_Tree[current].parent].right != NIL) return Binary_Tree[Binary_Tree[current].parent].right;
    return NIL;
}

void Print_Tree(int current){
    int i, c;
    printf("node %d: ", current);                               // 現在参照しているノード
    printf("parent %d, ", Binary_Tree[current].parent);         // そのノードの親
    printf("sibling %d, ", getSibling(current));                // そのノードの兄弟
    
    int degree = 0;                                                     // そのノードが持つ子の数
    if(Binary_Tree[i].left  != NIL) degree++;    
    if(Binary_Tree[i].right != NIL) degree++;    

    printf("degree %d, ", degree);                              // そのノードの深さ
    printf("depth %d, ", Depth[current]);                       // そのノードの深さ
    printf("depth %d, ", Height[current]);                      // そのノードの深さ

    if(Binary_Tree[current].parent == NIL){
        printf("root\n");                                       // そのノードが根ノードの場合(親が存在しない)
    }
    else if(Binary_Tree[current].left == NIL && Binary_Tree[current].right == NIL){
        printf("leaf\n");                                       // そのノードが葉ノードの場合
    }
    else{
        printf("internal node\n");                              // そのノードが内部ノードの場合
    }
}

// 各ノードを1回ずつ探索するのでO(n)のアルゴリズム
void setDepth(int current, int depth){
    if(current == NIL) return;
    Depth[current] = depth;                                             // Dにはノードcurrentの深さを格納
    setDepth(Binary_Tree[current].left,  depth + 1); 
    setDepth(Binary_Tree[current].right, depth + 1); 
}

// 各ノードを1回ずつ探索するのでO(n)のアルゴリズム
int setHeight(int current){
    int Height_1 = 0;
    int Height_2 = 0;

    if(Binary_Tree[current].left != NIL){
        Height_1 = setHeight(Binary_Tree[current].left) + 1;
    }
    if(Binary_Tree[current].right != NIL){
        Height_2 = setHeight(Binary_Tree[current].right) + 1;
    }
    return Height[current] = (Height_1 > Height_2) ? Height_1 : Height_2;
}

int main(void){
 
    int n, P, L, R, root = 0;
    int i, j;

    printf("N : ");
    scanf_s("%d", &n);

    for(i = 0; i < n; i++) {
        Binary_Tree[i].parent = NIL;
    }

    for(i = 0; i < n; i++){
        scanf_s("%d %d %d", &P, &L, &R);        
        Binary_Tree[P].left = L;
        Binary_Tree[P].right = R;
        if(L != NIL) Binary_Tree[L].parent = P;
        if(R != NIL) Binary_Tree[R].parent = P;
    }

    for(i = 0; i < n; i++){
        if(Binary_Tree[i].parent == NIL) root = i;                       
    }

    setDepth(root, 0);   // 各節点の深さを求める　(上からの距離)
    setHeight(root);            // 各節点の高さを求める  (下からの距離)

    for(i = 0; i < n; i++) Print_Tree(i);

    return 0;
}

/*

9
0 1 4
1 2 3
2 -1 -1
3 -1 -1
4 5 8
5 6 7
6 -1 -1
7 -1 -1
8 -1 -1

*/
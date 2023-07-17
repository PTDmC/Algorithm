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

void pre_Parse(int current){
    if(current == NIL) return;
    printf(" %d", current);
    pre_Parse(Binary_Tree[current].left);
    pre_Parse(Binary_Tree[current].right);
}

void in_Parse(int current){
    if(current == NIL) return;
    in_Parse(Binary_Tree[current].left);
    printf(" %d", current);
    in_Parse(Binary_Tree[current].right);
}

void post_Parse(int current){
    if(current == NIL) return;
    post_Parse(Binary_Tree[current].left);
    post_Parse(Binary_Tree[current].right);
    printf(" %d", current);
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

    puts("Preorder");
    pre_Parse(root);
    puts("");
    
    puts("Inorder");
    in_Parse(root);
    puts("");

    puts("Postorder");
    post_Parse(root);
    puts("");
    
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
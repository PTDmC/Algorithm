#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

///////////////////////////////////////////// 未完成 ////////////////////////////////////////////////////

#define N 100000
#define LIST_SIZE 100

typedef struct array{
    struct array *next, *prev;
    long num;
} NODE;

NODE *Nil;                                          // リストの最初に着ける番兵

void init(){
    Nil = (NODE *)malloc(sizeof(NODE));
    Nil->next = Nil;
    Nil->prev = Nil;
}

void print(){
    NODE *p;

    for(p = Nil->next; p != Nil; p = p->next){
        printf("%ld ", p->num);
    }
}

void delete(long x){
    
    NODE *p;

    for(p = Nil->next; p != Nil; p = p->next){
        if(p->num == x){
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            return;
        }
    }

    printf("This node does noe exist...");
}

void insert(long x){                                // 末尾ではなく先頭に付ける

    NODE *new;
    new = (NODE *)malloc(sizeof(NODE));
    new->next = Nil->next;                          // Nilの前にあったNodeをnewの前に差し替える
    new->prev = Nil;                                // newの後ろにNilが来るようにする
    Nil->next->prev = new;                          // Nilの前にあったNodeの後ろにnewが来るようにする
    Nil->next = new;                                // Nilの前にnewが来るようにする
    new->num = x;
}

#define INFTY (1 << 25)
#define WHITE 0     // 未訪問
#define GRAY  1     // 訪問中
#define BLACK 2     // 訪問済み
#define STACK_SIZE 100
int cnt = 0;

int  M[N][N] = {};

// DFSは可能な限り、ノードを訪問するアルゴリズムのこと。(訪問することが目的)

// あるノードから、各ノードへのエッジが存在するのかを確認するための計算量が1ノード当たり n回 存在する
// これをn個の各ノードで一回ずつ実行するので 計算量は O(n^2)

// ※ 一回ずつなのは、一度訪問したノードは未訪問ではなくなるため再び再帰されることが無いからである。

int Color[N], Discover_Time[N], Finish_Time[N], Nt[N];
int Current_Time;

long Stack[STACK_SIZE];
int stack_pointer = 0;

int is_Empty(){
    return stack_pointer == 0;
}

void push(long x){
    if(stack_pointer <= STACK_SIZE){
        Stack[stack_pointer++] = x;                     //[++x] と [x++] の二通りがある
    }
    else{
        printf("Stack is full!\n");
    }
}

char pop(){
    if(stack_pointer <= 0){
        printf("Stack is empty!\n");
        return -1;
    }
    return Stack[--stack_pointer];                      //[--x] と [x--] の二通りがある
}

int get_Next_Node(int Current_Node, int n){
    int Dest_Node;
    for(Dest_Node = Nt[Current_Node]; Dest_Node < n; Dest_Node++){  // エッジが存在するノードまで探索
        Nt[Current_Node] = Dest_Node + 1;                           // Dest_Nodeは小さい方から探索するので、次の呼び出しで行先を見つけるときは、前回見つけた行先ノードよりも後ろから探索するようにする。
        if(M[Current_Node][Dest_Node]) return Dest_Node;
    }
    return -1;
}

void DFS_Visit(int Start_Node, int n){

    int i;
    for(i = 0; i < n; i++) Nt[i] = 0;

    push(Start_Node);
    Color[Start_Node] = GRAY;                           // 訪問中にする
    Discover_Time[Start_Node] = ++Current_Time;         // 初訪問の時間を記録
    
    while(!is_Empty()){
        int Current_Node = Stack[stack_pointer - 1];    // スタックの一番上を参照して、現在注目しているノードを設定
        int Dest_Node = get_Next_Node(Current_Node, n); // その行先ノードを小さい順に取得

        if(Dest_Node != -1){                                // 行先が無くなるまでループ
            if(Color[Dest_Node] == WHITE){                  // 未訪問なら
                Color[Dest_Node] =GRAY;                     // 訪問中にする
                Discover_Time[Dest_Node] = ++Current_Time;  // 初訪問の時間を記録
                push(Dest_Node);                         // 行先ノードをスタックに積む
            }
        }
        else{
            pop();                                          // 行先が無くなったノードが無くなるまでpop
            Color[Current_Node] = BLACK;                    // 行先が無くなったら、始点ノードを訪問済みにする
            Finish_Time[Current_Node] = ++Current_Time;     // 訪問終了時間を記録
        }
    }
}

void DFS(int n){
    
    int Current_Node;
    
    for(Current_Node = 0; Current_Node < n; Current_Node++){
        Color[Current_Node] = WHITE;                                    // 初期化
        Nt[Current_Node] = 0;
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

    int i, Users, Friend_Relation, cn1, cn2;
    long x;

    init();

    NODE Graph[N];

    scanf("%d %d", &Users, &Friend_Relation);
    for(i = 0; i < Friend_Relation; i++){
        scanf("%d %d", &cn1, &cn2);
            insert(x);
    }

    puts("");

    print();

    return 0;
}
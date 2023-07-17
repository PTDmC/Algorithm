#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int main(){

    int i, n;
    long x;
    char com[10];

    init();

    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%s %ld", com, &x);
        if(strcmp("insert", com) == 0){
            insert(x);
        }
        else if(strcmp("delete", com) == 0){
            delete(x);
        }
    }

    puts("");

    print();

    return 0;
}

/*

7
insert 5
insert 2
insert 3
insert 1
delete 3
insert 6
delete 5
*/
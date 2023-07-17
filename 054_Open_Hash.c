#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUCKET_SIZE 100
#define EMPTY       0
#define NOTEMPTY    1
#define DELETED     2

typedef struct array{
    int flag;
    char key[20];
} BUCKET;

BUCKET Hash_Table[BUCKET_SIZE];

void init(){
    int i;
    for(i = 0; i < BUCKET_SIZE; i++){
        Hash_Table[i].flag = EMPTY;
    }
}

int h1(int key){
    return key % BUCKET_SIZE;   
}

int h2(int key){
    return 1 + (key % (BUCKET_SIZE - 1));   
}

int Hash(char key[], int i){
    int h, i_key = 0, p = 1;

    while(key[i] != '\0'){
        i_key += p * key[i];  
        i++;
        p *= 5;
    }

    return h = (h1(i_key) + i * h2(i_key)) % BUCKET_SIZE;
}

void print(){

    int count = 0;

    while(count < BUCKET_SIZE){
        if(Hash_Table[count].flag == NOTEMPTY)
            printf("Table[%d] : %s\n", count, Hash_Table[count].key);        
        count++;
    }
}

void insert(char key[]){

    int i = Hash(key, 0);
    int count = 0;

    while(Hash_Table[i].flag != EMPTY && Hash_Table[i].flag != DELETED){
        if(count >= BUCKET_SIZE){
            printf("Hash Table is full!\n");
            return;
        }
        if(!strcmp(Hash_Table[i].key, key)){
            printf("This key already exist in Hash Table!\n");
            return;
        }
        count++;
        i = Hash(key, count);
    }

    Hash_Table[i].flag = NOTEMPTY;;
    strcpy_s(Hash_Table[i].key, 20, key);

}

void delete(char key[]){

    int i = Hash(key, 0);
    int count = 0;

    while(Hash_Table[i].flag != EMPTY){
        if(count >= BUCKET_SIZE){
            printf("Hash Table is empty!\n");
            return;
        }
        if(!strcmp(Hash_Table[i].key, key)){
            Hash_Table[i].flag = DELETED;
            strcpy_s(Hash_Table[i].key, 20, key);
            return;
        }
        count++;
        i = Hash(key, count);
    }

    printf("This key doesn't exist...\n");
}

void find(char key[]){

    int i = Hash(key, 0);
    int count = 0;

    while(Hash_Table[i].flag != EMPTY){
        if(count >= BUCKET_SIZE){
            printf("Hash Table is empty!\n");
            return;
        }
        if(!strcmp(Hash_Table[i].key, key) && Hash_Table[i].flag == NOTEMPTY){
            printf("Find!\n");
            return;
        }
        count++;
        i = Hash(key, count);
    }

    printf("This key doesn't exist...\n");
}

int main(){

    int i, n;
    char x[20];
    char com[10];

    init();

    scanf_s("%d", &n);
    for(i = 0; i < n; i++){
        scanf_s("%s %s", com, x);
        if(strcmp("insert", com) == 0){
            insert(x);
        }
        else if(strcmp("delete", com) == 0){
            delete(x);
        }
        else if(strcmp("find", com) == 0){
            find(x);
        }
    }

    puts("");

    print();

    return 0;
}
/*

10
insert AAA
insert BBC
insert BCB
insert CBB
find BCB
delete BBC
find BBC
insert CBB
insert FGH
insert IJK

52
insert A
insert B
insert C
insert D
insert E
insert F
insert G
insert H
insert I
insert J
insert K
insert L
insert M
insert N
insert O
insert P
insert Q
insert R
insert S
insert T
insert U
insert V
insert W
insert X
insert Y
insert Z
insert AA
insert BB
insert CC
insert DD
insert EE
insert FF
insert GG
insert HH
insert II
insert JJ
insert KK
insert LL
insert MM
insert NN
insert OO
insert PP
insert QQ
insert RR
insert SS
insert TT
insert UU
insert VV
insert WW
insert XX
insert YY
insert ZZ

*/
#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200000

int GCD(int a, int b){
    return b ? GCD(b, a % b) :a;    // b が 0 なら a を返す
}

//  a  b
// 74 54             54 ? [(54, 20)] : 74     ( 74 % 54 = 20 )
// 54 20             20 ? [(20, 14)] : 54     ( 54 % 20 = 14 )
// 20 14             14 ? [(14,  6)] : 20     ( 20 % 14 =  6 )
// 14  6              6 ? [( 6,  2)] : 14     ( 14 %  6 =  2 )
//  6  2              2 ? [( 2,  0)] :  6     (  6 %  2 =  0 )
//  2  0              0 ?  ( 0,  0)  : [2]    return [2]


int main(){
    int a, b;

    printf("a : ");
    scanf("%d", &a);
    printf("b : ");
    scanf("%d", &b);

    puts("");
    printf("%d", GCD(a, b));

    return 0;
}

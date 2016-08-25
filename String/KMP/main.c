//
// Created by akka on 16/8/17.
//

#include "KMP.h"

int main(int argc, char **argv) {
    int L,i1,i2,pos,i;
    SString S,T;
    char *s = "abaddfanfdsafkafdkafkndasfna";
    char *t = "afdkafkn";

    StrAssign_Sq(S,s);
    StrAssign_Sq(T,t);

    L = StrLength_Sq(T);

    int next[L+1];
    int nextval[L+1];

    get_next(T,next);
    get_nextval(T,nextval);

    pos = 1;
    i1 = Index_KMP(S,T,pos,next);
    i2 = Index_KMP(S,T,pos,nextval);

    printf("main string:");

    StrPrint_Sw(S);

    printf("\n");

    printf("KMP queue:");

    StrPrint_Sw(T);

    printf("n\n");

    printf("next: ");

    for (i = 1 ; i <= L; ++i) {
        printf("%d",next[i]);
    }
    printf("\n");

    printf("从%d个字符起第一次匹配成功的位置为 i = %d\n",pos,i1);

    printf("\n");

    printf("nextval: ");

    for (i = 1; i < L; ++i) {
        printf("%d",nextval[i]);
    }

    printf("\n");

    printf("从%d个字符起第一次匹配成功的位置为i2 = %d\n",pos,i2);
    printf("\n");
    return 0;
}
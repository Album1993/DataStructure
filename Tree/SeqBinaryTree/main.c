//
// Created by 张一鸣 on 16/9/3.
//

#include <stdio.h>
#include "SeqBinaryTree.h"

void PrintElem(char c) {
    printf("%c ",c);
}

int main(int argc, char * argv[]) {
    SqBiTree T;

    printf("初始化空二叉树T...\n");
    InitBiTree_Sq(T);
    printf("\n");

    BiTreeEmpty_Sq(T) ? printf("T为空!\n"):printf("T不为空!\n");
    printf("\n");

    FILE*fp;

    printf("创建二叉树T\n");

    fp = fopen("/Users/zhangyiming/Documents/代码/DataStructure/Tree/SeqBinaryTree/TestData_Le.txt","r");

    CreateBiTree_Le_Sq(fp,T);

    fclose(fp);

    printf("\n");

    printf("打印二叉树\n");

    Print_Sq(T);
    printf("\n");

    printf("T的长度为:%d,depth is :%d",BiTreeLength_Sq(T),BiTreeDepth_Sq(T));

    printf("LevelOrderTraverse T:");

    LevelOrderTraverse_Sq(T,PrintElem);

    printf("\n\n");

    printf("PreOrderTraverse T:");

    PreOrderTraverse_Sq(T,PrintElem,0);

    printf("\n\n");
}

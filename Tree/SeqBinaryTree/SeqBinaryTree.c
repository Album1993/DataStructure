//
// Created by 张一鸣 on 16/9/3.
//

#include "SeqBinaryTree.h"
#include <math.h>
void InitBiTree_Sq(SqBiTree T) {
    int i;
    for (i = 0; i < MAX_TREE_SIZE; i++) {
        T[i] = '\0';
    }
}

void ClearBiTree_Sq(SqBiTree T) {
    int i;
    for (i = 0; i < MAX_TREE_SIZE; i++) {
        T[i] = '\0';
    }
}

void DestoryBiTree_Sq(SqBiTree T) {

}

Status BiTreeEmpty_Sq(SqBiTree T) {
    return T[0] == '\0' ? TRUE : FALSE;
}

// 一层一层赋值
Status CreateBiTree_Le_Sq(FILE *fp,SqBiTree T) {
    char ch;
    int i = 0;

    while (Scanf(fp,"%c",&ch) == 1 && ch!='\n') {
        if (ch == '^')
            T[i++] = '\0';
        else
            T[i++] = ch;
    }
    return OK;
}

Status CreateBiTree_Pre_Sq(FILE *fp,SqBiTree T, int i) {
    char ch;
    Scanf(fp,"%c",&ch);

    if (ch == '^')
        T[i] = '\0';
    else
    {
        T[i] = ch;
        CreateBiTree_Pre_Sq(fp,T,2*i + 1);
        CreateBiTree_Pre_Sq(fp,T,2*i + 2);
    }
    return OK;
}

int BiTreeLength_Sq(SqBiTree T) {
    int len;
    for (len = MAX_TREE_SIZE; len - 1 >=0 ; len--) {
        if (T[len - 1]!='\0')
            break;
    }
    return len;
}

int BiTreeDepth_Sq(SqBiTree T) {
    int level = 0;
    while ((int)pow(2,level) - 1 < BiTreeLength_Sq(T))
        level++;
    return level;
}

Status Root_Sq(SqBiTree T,TELemType_Sq *e) {
    if (BiTreeEmpty_Sq(T))
        return ERROR;

    *e = T[0];
    return OK;
}

TELemType_Sq Value_Sq(SqBiTree T,Position s) {
    int i = (int)pow(2,s.level - 1) + s.order - 2;
    return T[i];
}

Status Assign_Sq(SqBiTree T,Position s, TELemType_Sq value) {
    int i = (int)pow(2,s.level-1) + s.order-2;
    if (value == '\0' && (T[2*i+1]!='\0'|| T[2*i+2]!='\0')) // 如果存在子节点但当前节点为空，那就是错的
        return ERROR;
    else if (value != '\0' && T[(i+1)/2 - 1] == '\0') // 父节点也不能为空
        return ERROR;
    else
        T[i] = value;
    return OK;
}

TELemType_Sq Parent_Sq(SqBiTree T,TELemType_Sq e) {
    int i;
    if (T[0]!= '\0') {
        for (i = 0; i < MAX_TREE_SIZE; i++) {
            if (T[i] == e)
                return T[(i+1)/2 - 1];
        }
    }
    return '\0';
}

TELemType_Sq LeftChild_Sq(SqBiTree T,TELemType_Sq e) {
    int i;
    if (T[0] == '\0')
        return '\0';

    for (i = 0; i < MAX_TREE_SIZE; i++) {
        if (T[i] == e)
            return T[2*i + 1];
    }
    return '\0';
}

TELemType_Sq RightChild_Sq(SqBiTree T,TELemType_Sq e) {
    int i;
    if (T[0] == '\0')
        return '\0';

    for (i = 0; i < MAX_TREE_SIZE; i++) {
        if (T[i] == e)
            return T[2*i + 2];
    }
    return '\0';
}

TELemType_Sq LeftSibling_Sq(SqBiTree T,TELemType_Sq e) {
    int i;
    if (T[0] == '\0')
        return '\0';

    for (i = 0; i < MAX_TREE_SIZE; i++) {
        if (i%2==0 && T[i] == e)
            return T[i-1];
    }
    return '\0';
}

TELemType_Sq RightSibling_Sq(SqBiTree T,TELemType_Sq e) {
    int i;
    if (T[0]=='\0')
        return '\0';
    for (i = 0; i < MAX_TREE_SIZE; i++) {
        if (i%2!=0 && T[i] == e)
            return T[i+1];
    }
    return '\0';
}

void LevelOrderTraverse_Sq(SqBiTree T,void(Visit)(TELemType_Sq)) {
    int i;
    int len = BiTreeLength_Sq(T);

    for (i = 0; i < len; i++) {
        if (T[i] != '\0')
            Visit(T[i]);
    }
}

void PreOrderTraverse_Sq(SqBiTree T,void(Visit)(TELemType_Sq),int i) {
    if (T[i] != '\0') {
        Visit(T[i]);
        PreOrderTraverse_Sq(T,Visit,2*i+1);
        PreOrderTraverse_Sq(T,Visit,2*i+2);
    }
}

void InOrderTraverse_Sq(SqBiTree T,void(Visit)(TELemType_Sq), int i) {
    if (T[i] != '\0') {
        InOrderTraverse_Sq(T,Visit,2*i+1);
        Visit(T[i]);
        InOrderTraverse_Sq(T,Visit,2*i+2);
    }
}

void PostOrderTraverse_Sq(SqBiTree T, void(Visit)(TELemType_Sq), int i ) {
    if (T[i] != '\0') {
        PostOrderTraverse_Sq(T,Visit,2*i+1);
        PostOrderTraverse_Sq(T,Visit,2*i+2);
        Visit(T[i]);
    }
}

void Print_Sq(SqBiTree T) {
    int i,j,level;
    char tmp[MAX_TREE_SIZE][MAX_TREE_SIZE] = {};
    level = BiTreeDepth_Sq(T);

    for (i = 1; i <= level; i++) {
        for (j = 1; j <= (int)pow(2,i-1) ; j++) {
            tmp[i-1][(int)pow(2,level-i) + (j-1)*(int)pow(2,level-i+1)-1] = T[(int)pow(2,i-1)-1+j-1];
        }
    }

    for (i = 0; i < level ;i++) {
        for (j = 0; j < 2*(int)pow(2,level-1)-1; j++) {
            if (tmp[i][j] != '\0')
                printf("%c ",tmp[i][j]);
            else
                printf(" ");
        }
        printf("\n");
    }
}

//
// Created by 张一鸣 on 16/9/3.
//

#ifndef SEQBINARYTREE_SEQBINARYTREE_H
#define SEQBINARYTREE_SEQBINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"
#include "Scanf.h"

#define MAX_TREE_SIZE 100

typedef char TELemType_Sq;
typedef TELemType_Sq SqBiTree[MAX_TREE_SIZE];

typedef struct {
    int level;
    int order;
}Position;

void InitBiTree_Sq(SqBiTree T);

void ClearBiTree_Sq(SqBiTree T);

void DestoryBiTree_Sq(SqBiTree T);

Status BiTreeEmpty_Sq(SqBiTree T);

Status CreateBiTree_Le_Sq(FILE *fp,SqBiTree T);

Status CreateBiTree_Pre_Sq(FILE *fp,SqBiTree T, int i);

int BiTreeLength_Sq(SqBiTree T);

int BiTreeDepth_Sq(SqBiTree T);

Status Root_Sq(SqBiTree T,TELemType_Sq *e);

TELemType_Sq Value_Sq(SqBiTree T,Position s);

Status Assign_Sq(SqBiTree T,Position s, TELemType_Sq value);

TELemType_Sq Parent_Sq(SqBiTree T,TELemType_Sq e);

TELemType_Sq LeftChild_Sq(SqBiTree T,TELemType_Sq e);

TELemType_Sq RightChild_Sq(SqBiTree T,TELemType_Sq e);

TELemType_Sq LeftSibling_Sq(SqBiTree T,TELemType_Sq e);

TELemType_Sq RightSibling_Sq(SqBiTree T,TELemType_Sq e);

void LevelOrderTraverse_Sq(SqBiTree T,void(Visit)(TELemType_Sq));

void PreOrderTraverse_Sq(SqBiTree T,void(Visit)(TELemType_Sq),int i);

void InOrderTraverse_Sq(SqBiTree T,void(Visit)(TELemType_Sq), int i);

void PostOrderTraverse_Sq(SqBiTree T, void(Visit)(TELemType_Sq), int i );

void Print_Sq(SqBiTree T);


#endif //SEQBINARYTREE_SEQBINARYTREE_H

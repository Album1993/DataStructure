//
// Created by 张一鸣 on 2016/12/1.
//

#ifndef MGRAPH_MGRAPH_H
#define MGRAPH_MGRAPH_H

#include <stdlib.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>
#include "Status.h"
#include "Scanf.c"
#include "LinkQueue.h"

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20

typedef enum {DG , DN ,UDG ,UDN} GraphKind;
typedef struct {} InfoType;
typedef int VRType;
typedef struct ArcCell {
    VRType adj; //权重
    InfoType info; // 弧相关
}ArcCell;

typedef ArcCell AdjMatrix[MAX_VERTEX_NUM + 1][MAX_VERTEX_NUM + 1];
typedef char VertexType_M;
typedef struct {
    VertexType_M vexs[MAX_VERTEX_NUM + 1];
    AdjMatrix arcs;
    int vexnum,arcnum;
    int IncInfo;
    GraphKind kind;
}MGraph;

Status visited[MAX_VERTEX_NUM + 1];
void (*VisitFunc)(VertexType_M e);

Status CreateGraph_M(FILE * fp,MGraph *G);

Status CreateDG_M(FILE *fp,MGraph *G);
Status CreateDN_M(FILE *fp,MGraph *G);
Status CreateUDG_M(FILE *fp,MGraph *G);
Status CreateUDN_M(FILE *fp,MGraph *G);

void ClearGraph_M(MGraph *G);

int LocateVex_M(MGraph G,VertexType_M u);

VertexType_M GetVet_M(MGraph G, int order);

Status PutVex_M(MGraph *G,VertexType_M v, VertexType_M value);

int FirsAdjVex_M(MGraph G,VertexType_M v);

int NextAdjVex_M(MGraph G,VertexType_M v,VertexType_M w);

Status InsertVex_M(MGraph *G,VertexType_M v);

Status DeleteVex_M(MGraph *G,VertexType_M v);

Status InsertArc_M(MGraph *G,VertexType_M v,VertexType_M w,VRType adj,...);

Status DeleteArc_M(MGraph *G,VertexType_M v,VertexType_M w);

void DFSTraverse_M(MGraph G, void(Visit)(VertexType_M));

void DFS_M(MGraph G, void(Visit)(VertexType_M));

void BFSTraverse_M(MGraph G, void(Visit)(VertexType_M));

void OutputMGraph(MGraph G);

void Input(FILE *fp,InfoType * info);

#endif //MGRAPH_MGRAPH_H

//
// Created by 张一鸣 on 2016/12/1.
//

#include "MGraph.h"

Status CreateGraph_M(FILE * fp,MGraph *G) {
    Scanf(fp, "%d",&((*G).kind));
    switch ((*G).kind) {
        case DG:
            return CreateDG_M(fp,DG);
        case DN:
            return CreateDN_M(fp,DN);
        case UDG:
            return CreateUDG_M(fp,UDG);
        case UDN:
            return CreateUDN_M(fp,UDN);
        default:
            return ERROR;
    }
}

Status CreateDG_M(FILE *fp,MGraph *G) {
    int i,j,k;
    VertexType_M v1,v2;
    char tmp;

    Scanf(fp,"%d%d%d",&((*G).vexnum),&((*G).arcnum),&((*G).IncInfo));
    Scanf(fp,"%c",&tmp);

    for ( i = 1; i <= (*G).vexnum; i++) {
        for (j = 1;j <= (*G).vexnum;j++) {
            (*G).arcs[i][j].adj = 0;
        }
    }
    for (k = 1; k <= (*G).arcnum ; k++) {
        Scanf(fp,"%c%c",&v1,&v2);
        i = LocateVex_M(*G,v1);
        j = LocateVex_M(*G,v2);

        if (!i || !j)
            return ERROR;
        (*G).arcs[i][j].adj = 1;
        if ((*G).IncInfo == 1)
            Input(fp,&((*G).arcs[i][j].info));
    }
    return OK;
}

Status CreateDN_M(FILE *fp,MGraph *G) {
    int i,j,k;
    VertexType_M v1,v2;
    VRType w;
    char tmp;

    Scanf(fp,"%d%d%d",&((*G).vexnum),&((*G).arcnum),&((*G).IncInfo));
    Scanf(fp,"%c",&tmp);

    for (i = 1; i <= (*G).vexnum ; i++) {
        for (j = 1; j <= (*G).vexnum; j++) {
            (*G).arcs[i][j].adj = INFINITY;
        }
    }

    for (i = 1; i <= (*G).vexnum; i++) {
        for (j = 1; j <= (*G).vexnum ; j++) {
            (*G).arcs[i][j].adj = INFINITY;
        }
    }

    for (k = 1; k < ; ++k) {

    }
}

Status CreateUDG_M(FILE *fp,MGraph *G) {

}
Status CreateUDN_M(FILE *fp,MGraph *G) {

}

void ClearGraph_M(MGraph *G) {
    (*G).vexnum = 0;
    (*G).arcnum =0;
    (*G).IncInfo = 0;
}

int LocateVex_M(MGraph G,VertexType_M u) {
    int i;
    for (i = 1; i <= G.vexnum; i++) {
        if (G.vexs[i] == u)
            return i;
    }
    return 0;
}

VertexType_M GetVet_M(MGraph G, int order) {
    if (order >= 1 && order <= G.vexnum)
        return G.vexs[order];
    else
        return '\0';
}

Status PutVex_M(MGraph *G,VertexType_M v, VertexType_M value) {
    int k ;
    k = LocateVex_M(*G,v);
    if (k) {
        (*G).vexs[k] = value;
        return OK;
    } else {
        return ERROR;
    }
}

int FirstAdjVex_M(MGraph G, VertexType_M v) {
    int k,j,t;
    k = LocateVex_M(G,v);
    if (k) {
        if (G.kind % 2)
            t = INFINITY;
        else
            t = 0;
        for (j = 1; j <= G.vexnum ; j++) {
            if (G.arcs[k][j].adj != t)
                return j;
        }
    }
    return 0;
}

int NextAdjVex_M(MGraph G,VertexType_M v,VertexType_M w) {
    int k1,k2,j,t;
    k1 = LocateVex_M(G,v);
    k2 = LocateVex_M(G,w);
    if (k1 && k2) {
        if (G.kind%2)
            t = INFINITY;
        else
            t = 0;
        for (j = k2 + 1; j <= G.vexnum; j++) {
            if (G.arcs[k1][j].adj != t)
                return j;
        }
    }
    return 0;
}

Status InsertVex_M(MGraph *G,VertexType_M v) {
    int i,k,t;
    if ((*G).vexnum == MAX_VERTEX_NUM)
        return ERROR;

    if ((*G).kind%2)
        t = INFINITY;
    else
        t = 0;

    k = (*G).vexnum + 1;
    (*G).vexs[k] = v;

    for (i = 0; i <= k; i++) {
        (*G).arcs[i][k].adj = t;
        (*G).arcs[k][i].adj = t;
    }
    (*G).vexnum++;
    return OK;
}

Status DeleteVex_M(MGraph *G,VertexType_M v) {
    int i, j, k, t;
    k = LocateVex_M(*G,v);
    if (!k)
        return ERROR;

    if ((*G).kind % 2)
        t = INFINITY;
    else
        t = 0;

    for (i = 1; i <= k; i++) {
        if ((*G).arcs[k][i].adj != t)
            (*G).arcnum--;
        if ((*G).kind == DG || (*G).kind ==DN) {
            if ((*G).arcs[i][k].adj != t)
                (*G).arcnum--;
        }
    }

    for (i = 1; i <= (*G).vexnum ; i++) {
        for ( j = k + 1; j <= (*G).vexnum ; ++k) {
            (*G).arcs[i][j-1] = (*G).arcs[i][j];
        }
    }
    for (i = k+1; i <= (*G).vexnum ; i++) {
        for (j = 1; j <= (*G).vexnum - 1; j++) {
            (*G).arcs[i - 1][j] = (*G).arcs[i][j];
        }
    }
    (*G).vexnum--;
    return OK;
}

Status InsertArc_M(MGraph *G,VertexType_M v,VertexType_M w,VRType adj,...) {
    int k1,k2;
    k1 = LocateVex_M(*G,v);
    k2 = LocateVex_M(*G,w);

    if (!k1 || !k2)
        return ERROR;

    (*G).arcs[k1][k2].adj = adj;
    va_list ap;
    va_start(ap,adj);
    (*G).arcs[k1][k2].info = va_arg(ap,InfoType);
    va_end(ap);

    if ((*G).kind == UDG || (*G).kind == UDN)
        (*G).arcs[k2][k1] = (*G).arcs[k1][k2];
    (*G).arcnum++;
    return OK;
}

Status DeleteArc_M(MGraph *G,VertexType_M v,VertexType_M w) {
    int k1, k2;
    k1 = LocateVex_M(*G,v);
    k2 = LocateVex_M(*G,w);

    if (!k1 || !k2)
        return ERROR;
    if ((*G).kind % 2)
        (*G).arcs[k1][k2].adj = INFINITY;
    else
        (*G).arcs[k1][k2].adj = 0;

    if ((*G).kind == UDG || (*G).kind == UDG)
        (*G).arcs[k2][k1] = (*G).arcs[k1][k2];
    (*G).arcnum--;
    return OK;
}

void DFSTraverse_M(MGraph G, void(Visit)(VertexType_M)) {
    int v;
    VisitFunc = Visit;
    for (v = 1; v <= G.vexnum ; ++v) {
        visited[v] = FALSE;
    }

    for (v = 1; v < G.vexnum; v++) {
        if (!visited[v])
            DFS_M(G,v);
    }
}

void DFS_M(MGraph G, int v) {
    int w;
    visited[v] = TRUE;
    VisitFunc(G.vexs[v]);
    for (w = FirstAdjVex_M(G, G.vexs[v]);w; w = NextAdjVex_M(G,G.vexs[v],G.vexs[w])) {
        if (!visited[w])
            DFS_M(G,w);
    }
}

void BFSTraverse_M(MGraph G, void(Visit)(VertexType_M)) {
    int v,w;
    LinkQueue Q;
    QElemType_L e;

    for (v = 1; v <= G.vexnum; v++) {
        visited[v] = FALSE;
    }

    InitQueue_L(&Q);
    for ( v = 1; v <= G.vexnum ; v++) {
        if(!visited[v]) {
            visited[v] = TRUE;
            Visit(G.vexs[v]);
            EnQueue_L(&Q, v);
            while (!QueueEmpty_L(Q)) {
                DeQueue_L(&Q,&e);
                for (w = FirstAdjVex_M(G,G.vexs[e]); w ;w = NextAdjVex_M(G,G.vexs[e],G.vexs[w])) {
                    if (!visited[w]) {
                        visited[w] = TRUE;
                        Visit(G.vexs[w]);
                        EnQueue_L(&Q, w);
                    }
                }
            }
        }
    }
}

void OutputMGraph(MGraph G) {
    int i,j;
    if (!G.vexnum && !G.arcnum)
        printf("空图");
    else {
        printf(" ");
        for (i = 0; i <= G.vexnum; i++) {
            printf("%2c ",G.vexs[i]);
        }
        printf("\n");

        for (i = 0; i <= G.vexnum; i++) {
            printf("%c ",G.vexs[i]);
            for (j = 1; j <= G.vexnum; j++) {
                if (G.arcs[i][j].adj == INFINITY)
                    printf("infinite ");
                else
                    printf("%2d ",G.arcs[i][j]);
            }
            printf("\n");
        }
    }
}

void Input(FILE *fp,InfoType * info) {
    
}

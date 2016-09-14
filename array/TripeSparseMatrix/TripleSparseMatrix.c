//
// Created by akka on 16/9/2.
//

#include "TripleSparseMatrix.h"
Status CreateSMatrix_T(FILE * fp, int n, ...) {
    int count,k;
    TSMatrix *M;

    if (n < 1) return ERROR;

    va_list ap;
    va_start(ap,n);

    for (count = 1 ; count <= n; ++count) {
        M = va_arg(ap,TSMatrix*);
        Scanf(fp,"%d%d%d",&((*M).mu),&((*M).nu),&((*M).tu));

        printf("\n\n%d%d%d\n\n",((*M).mu),((*M).nu),((*M).tu));

        for (k = 1 ; k <= (*M).tu; ++k) {

            Scanf(fp,"%d%d%d",&((*M).data[k].i),&((*M).data[k].j),&((*M).data[k].e));

            printf("\n\n%d%d%d  %d %d  \n\n",((*M).data[k].i),((*M).data[k].j),((*M).data[k].e),k,(*M).tu);
        }
    }

    va_end(ap);
    printf("ok\n");
    return OK;
}

void DestoryMatrix_T(TSMatrix *M) {
    (*M).mu = 0;
    (*M).nu = 0;
    (*M).tu = 0;
}

void PrintSMatrix_T(TSMatrix M) {
    int r,c;
    int k = 1;
    for (r = 1; r <= M.mu ; ++r) {
        for (c = 1; c <= M.nu ; ++c) {
            if(r == M.data[k].i && c == M.data[k].j) {
                printf("%3d ",M.data[k].e);
                k++;
            } else {
                printf("  0 ");
            }
        }
        printf("\n");
    }
}

void CopySMatrix_T(TSMatrix M,TSMatrix *T) {
    *T = M;
}

Status AddMatri_T(TSMatrix M,TSMatrix N,TSMatrix *Q) {
    int m,n,k;
    if (M.mu != N.mu || M.nu != N.nu) {
        printf("two matrix cant be added");
        return ERROR;
    }

    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;

    m = n = k = 1;

    while (m <= M.tu && n <= N.tu) {
        if (M.data[m].i < N.data[n].i) {
            Q->data[k] = M.data[m];
            m++;
        } else if (M.data[m].i>N.data[n].i) {
            Q->data[k] = N.data[n];
            n++;
        } else {
            if (M.data[m].j < N.data[n].j) {
                Q->data[k] = M.data[m];
                m++;
            } else if (M.data[m].j > N.data[n].j) {
                Q->data[k] = N.data[n];
                n++;
            } else {
                if (M.data[m].e + N.data[n].e) {
                    Q->data[k].i = M.data[m].i;
                    Q->data[k].j = M.data[m].j;
                    Q->data[k].e = M.data[m].e + N.data[n].e;
                    m++;
                    n++;
                } else {
                    m++;
                    n++;
                    continue;
                }
            }
        }
        k++;
        Q->tu++;
    }

    while (m<=M.tu) {
        Q->data[k] = M.data[m];
        m++;
        k++;
        Q->tu++;
    }

    while (n <= N.tu) {
        Q->data[k] = N.data[n];
        n++;
        k++;
        Q->tu++;
    }
    return OK;

}

Status SubSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q) {
    int m,n,k;
    if (M.mu != N.mu || M.nu!=N.nu) {
        printf("two matrix cant be sub");
        return ERROR;
    }

    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;

    m = n = k = 1;

    while (m <= M.tu && n <= N.tu) {
        if (M.data[m].i < N.data[n].i) {
            Q->data[k] = M.data[m];
            m++;
        } else if (M.data[m].i>N.data[n].i) {
            Q->data[k].i = N.data[n].i;
            Q->data[k].j = N.data[n].j;
            Q->data[k].e = -N.data[n].e;
            n++;
        } else {
            if (M.data[m].j < N.data[n].j) {
                Q->data[k] = M.data[m];
                m++;
            } else if (M.data[m].j > N.data[n].j) {
                Q->data[k].i = N.data[n].j;
                Q->data[k].j = N.data[n].j;
                Q->data[k].e = -N.data[n].e;
                n++;
            } else {
                if (M.data[m].e - N.data[n].e) {
                    Q->data[k].i = M.data[m].i;
                    Q->data[k].j = M.data[m].j;
                    Q->data[k].e = M.data[m].e - N.data[n].e;
                    m++;
                    n++;
                } else {
                    m++;
                    n++;
                    continue;
                }
            }
        }
        k++;
        Q->tu++;
    }

    while (m <= M.tu) {
        Q->data[k] = M.data[m];
        m++;
        k++;
        Q->tu++;
    }

    while (n <= N.tu) {
        Q->data[k].i = N.data[n].i;
        Q->data[k].j = N.data[n].j;
        Q->data[k].e = -N.data[n].e;
        n++;
        k++;
        Q->tu++;
    }

    return OK;

}

Status MultiSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q) {
    int m,n,i,j,k;
    MElemType_TSq c,c1,c2;

    if (M.nu != N.mu) {
        printf("matrix cant be multied");
        return ERROR;
    }

    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;

    if (M.tu * N.tu) {
        for (i = 1 ; i <= M.mu; ++i) {
            for (j = 1; j < N.nu; ++j) {
                c1 = 0;
                for (m = 1; m <= M.tu; ++m) {
                    if (M.data[m].i == i && M.data[m].j == k) {
                        c1 = M.data[m].e;
                        break;
                    }
                }

                c2 = 0;
                for (n = 1 ; n < N.tu; ++n) {
                    if (N.data[n].i == k && N.data[n].j == j) {
                        c2 = N.data[n].e;
                        break;
                    }
                }
                if (c1 && c2)
                    c += c1 * c2;
            }

            if (c) {
                Q->tu++;
                Q->data[Q->tu].i = i;
                Q->data[Q->tu].j = j;
                Q->data[Q->tu].e = c;
            }
        }
    }
    return OK;
}

void TransposeSMatrix(TSMatrix M,TSMatrix *T) {
    int p,q,col;
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;

    if (T->tu) {
        q = 1;
        for (col = 1; col <= M.nu; ++col) {
            for (p = 1; p <=M.tu ; ++p) {
                if (M.data[p].j == col) {
                    T->data[q].i = M.data[p].j;
                    T->data[q].j = M.data[p].i;
                    T->data[q].e = M.data[p].e;
                    ++q;
                }
            }
        }
    }
}

void FastTransposeSMatrix_T(TSMatrix M,TSMatrix *T) {
    int col,t,p,q;
    int num[M.nu];
    int copt[M.nu];

    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;

    if (T->tu) {
        for (col = 1; col <= M.nu; ++col) {
            num[col] = 0;
            printf("%d ",col);
        }

        printf("\n");
        for (t = 1; t <= M.tu; ++t) {
            num[M.data[t].j]++;
            printf("%d ",M.data[t].j);
            printf("%d\n ",num[M.data[t].j]);
        }
        printf("\n");
        copt[1] = 1;
        for (col = 2; col <= M.nu; ++col) {
            copt[col] = copt[col - 1] + num[col - 1];
        }

        for (p = 1; p <= M.tu; ++p) {
            col = M.data[p].j;
            q = copt[col];
            T->data[q].i = M.data[p].j;
            T->data[q].j = M.data[p].i;
            T->data[q].e = M.data[p].e;
            ++copt[col];
        }
    }
}
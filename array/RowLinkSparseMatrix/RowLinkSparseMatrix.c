//
// Created by akka on 16/9/11.
//

#include "RowLinkSparseMatrix.h"

Status CreateSMatrix_RL(FILE *fp, int n,...) {
    int count,k;
    RLSMatrix *M;
    if (n < 1)
        return ERROR;
    va_list ap;
    va_start(ap,n);

    for (count = 1 ; count <= n; ++count) {
        M = va_arg(ap,RLSMatrix *);
        for (k = 0; k <= MAXRC; ++k)
            (*M).rpos[k] = 0;
        Scanf(fp,"%d%d%d",&((*M).mu),&((*M).nu),&((*M).tu));

        for (k = 1; k <= (*M).tu ; ++k) {
            Scanf(fp,"%d%d%d",&((*M).data[k].i),&((*M).data[k].j),&((*M).data[k].e));
            if ((*M).rpos[(*M).data[k].i] == 0)
                (*M).rpos[(*M).data[k].i] = k;
        }

        for (k = (*M).mu; k >= 1 ; --k) {
            if ((*M).rpos[k] == 0) {
                if (k == (*M).mu)
                    (*M).rpos[k] = (*M).tu + 1;
                else
                    (*M).rpos[k] = (*M).rpos[k+1];
            }
        }
    }

    va_end(ap);
    return OK;
}

void DestorySMatrix_RL(RLSMatrix *M) {
    int i;
    
    M->mu = 0;
    M->nu = 0;
    M->tu = 0;

    for (i = 0;  i <= MAXRC; ++i) {
        M->rpos[i] = 0;
    }
}

void PrintSMatrix_RL(RLSMatrix M) {
    int r,c;
    int k = 1;

    for (r = 1 ; r <= M.mu; ++r) {
        for (c = 1; c <= M.nu; ++c) {
            if(r == M.data[k].i && c == M.data[k].j) {
                printf("%3d",M.data[k].e);
                k++;
            } else
                printf("  0");
        }
        printf("\n");
    }
    printf("rpos = ");
    for (k = 1 ; k <= M.mu ; ++k) {
        printf("%d",M.rpos[k]);
    }
    printf("\n");
}

void CopySMatrix_RL(RLSMatrix M, RLSMatrix *T) {
    (*T) = M;
}

Status AddSMatrix_RL(RLSMatrix M,RLSMatrix N,RLSMatrix *Q) {
    int m,n,k;
    int i;

    if (M.mu != N.mu || M.nu != N.nu) {
        printf("two matrix cant be added");
        return ERROR;
    }

    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;
    m = n = k = 1;

    while (m<=M.tu && n <= N.tu) {
        if (M.data[m].i < N.data[n].i) {
            Q->data[k] = M.data[m];
            m++;
        } else if (M.data[m].i > N.data[n].i) {
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
    while  (m <= M.tu) {
        Q->data[k] = M.data[m];
        m++;
        k++;
        Q->tu++;
    }

    while (m <= N.tu) {
        Q->data[k] = N.data[n];
        n++;
        k++;
        Q->tu++;
    }

    for (i = 0; i <=  MAXRC; ++i) {
        Q->rpos[i] = 0;
    }

    for (i = 1; i <= Q->tu; ++i) {
        m = Q->data[i].i;
        if (Q->rpos[m] == 0)
            Q->rpos[m] = i;
    }

    for (i = Q->mu ; i >= 1 ; --i) {
        if (Q->rpos[i] == 0) {
            if (i == Q->mu)
                Q->rpos[i] = Q->tu + 1;
            else
                Q->rpos[i] = Q->rpos[i+1];
        }
    }
    return OK;
}

Status SubSMatrix_RL(RLSMatrix M,RLSMatrix N,RLSMatrix *Q) {
    int m,n,k;
    int i;

    if (M.mu != N.mu || M.nu != N.nu){
        printf("cant be sub");
        return ERROR;
    }

    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;
    m = n = k = 1;

    while (m <= M.tu && n<=N.tu) {
        if (M.data[m].i < N.data[n].i) {
            Q->data[k] = M.data[m];
            m++;
        } else if (M.data[m].i > N.data[n].i) {
            Q->data[k].i = N.data[n].i;
            Q->data[k].j = N.data[n].j;
            Q->data[k].e = -N.data[n].e;
            n++;
        } else {
            if (M.data[m].j < N.data[n].j) {
                Q->data[k] = M.data[m];
                m++;
            } else if (M.data[m].j < N.data[n].j) {
                Q->data[k].i = N.data[n].i;
                Q->data[k].j = N.data[n].j;
                Q->data[k].e = -N.data[n].e;
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
        Q->data[k].e = N.data[n].e;

        n++;
        k++;
        Q->tu++;
    }

    for (i = 0; i <= MAXRC; ++i) {
        Q->rpos[i] = 0;
    }

    for (i = 1; i <= Q->tu; ++i) {
        m = Q->data[i].i;
        if (Q->rpos[m] == 0)
            Q->rpos[m] = i;
    }

    for (i = Q->mu ; i >= 1; --i) {
        if (Q->rpos[i] == 0) {
            if (i == Q->mu)
                Q->rpos[i] = Q->tu + 1;
            else
                Q->rpos[i] = Q->rpos[i+1];
        }
    }
    return OK;
}

Status MultSMatrix_RL(RLSMatrix M,RLSMatrix N,RLSMatrix *Q) {
    int arow,brow,p,q,tp,tq,ccol;
    int ctemp[N.nu + 1];
    int i,m;

    if (M.nu != N.mu) {
        printf("cant be multi");
        return ERROR;
    }

    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;

    if (M.tu*N.tu) {
        for (arow = 1; arow <= M.mu ; ++arow) {
            for (i = 0; i <= N.nu; ++i)
                ctemp[i] = 0;
            if (arow < M.mu)
                tp = M.rpos[arow + 1];
            else
                tp = M.tu + 1;
            for (p = M.rpos[arow]; p < tp; ++p) {
                brow = M.data[p].j;

                if (brow < N.mu)
                    tq = N.rpos[brow + 1];
                else
                    tq = N.tu + 1;

                for (q = N.rpos[brow]; q < tq; ++q) {
                    ccol = N.data[q].j;
                    ctemp[ccol] += M.data[p].e * N.data[q].e;
                }
            }

            for (ccol = 1 ; ccol <= Q->nu ; ++ccol) {
                if (ctemp[ccol]) {
                    ++Q->tu;
                    if (Q->tu > MAXSIZE)
                        return ERROR;
                    Q->data[Q->tu].i = arow;
                    Q->data[Q->tu].j = ccol;
                    Q->data[Q->tu].e = ctemp[ccol];
                }
            }
        }
    }

    for (i = 0; i <= MAXRC; ++i) {
        Q->rpos[i] = 0;
    }

    for (i = 1; i < Q->tu; ++i) {
        m = Q->data[i].i;
        if (Q->rpos[m] == 0)
            Q->rpos[m] = i;
    }

    for (i = Q->mu; i >= 1; --i) {
        if (Q->rpos[i] == 0) {
            if (i == Q->mu)
                Q->rpos[i] = Q->tu + 1;
            else
                Q->rpos[i] = Q->rpos[i + 1];
        }
    }

    return OK;

}

void TransposeSMatrix_RL(RLSMatrix M,RLSMatrix *T) {
    int p,q,col;
    int i,m;
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;

    for (i = 0; i <= MAXRC; ++i) {
        T->rpos[i] = 0;
    }

    if (T->tu) {
        q = 1;
        for (col = 1; col <= M.nu; ++col) {
            for (p = 1; p <= M.tu ; ++p) {
                if (M.data[p].j == col) {
                    T->data[q].i = M.data[p].j;
                    T->data[q].j = M.data[p].i;
                    T->data[q].e = M.data[p].e;
                    if (T->rpos[col] == 0)
                        T->rpos[col] = q;
                    ++q;
                }
            }
        }
    }

    for (i = T->mu; i >= 1; --i) {
        if (T->rpos[i] == 0) {
            if (i == T->mu)
                T->rpos[i] = T->tu + 1;
            else
                T->rpos[i] = T->rpos[i+1];
        }
    }
}

void FastTransposeSMatrix_RL(RLSMatrix M,RLSMatrix *T) {
    int col,t,p,q;
    int num[M.nu];
    int copt[M.nu];
    int i,m;

    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;

    if (T->tu) {
        for (col = 1; col <= M.nu ; ++col) {
            num[col] = 0;
        }

        for (t = 1; t <= M.tu ; ++t) {
            ++num[M.data[t].j];
        }

        copt[1] = 1;

        for (col = 2; col <= M.nu ; ++col) {
            copt[col] = copt[col-1] + num[col - 1];
        }

        for (p = 1; p <= M.tu ; ++p) {
            col = M.data[p].j;
            q = copt[col];
            T->data[q].i = M.data[p].j;
            T->data[q].j = M.data[p].i;
            T->data[q].e = M.data[p].e;
            ++copt[col];
        }
    }
    for (i = 0; i <= MAXRC; ++i) {
        T->rpos[i] = 0;
    }

    for (i = 1; i <= T->tu ; ++i) {
        m = T->data[i].i;
        if (T->rpos[m] == 0)
            T->rpos[m] = i;
    }

    for (i = T->mu; i >= 1 ; --i) {
        if (T->rpos[i] == 0) {
            if (i == T->mu)
                T->rpos[i] = T->tu + 1;
            else
                T->rpos[i] = T->rpos[i+1];
        }
    }
}


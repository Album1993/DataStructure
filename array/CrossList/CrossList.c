//
// Created by 张一鸣 on 16/9/17.
//

#include "CrossList.h"
Status CreateSMatrix_OL(FILE *fp, int n,...) {
    int count,k;
    OLNode *p,*q;
    CrossList *M;

    if (n < 1)
        return ERROR;

    va_list ap;
    va_start(ap,n);

    for (count = 1; count <= n; ++count) {
        M = va_arg(ap,CrossList *);
        Scanf(fp,"%d%d%d",&((*M).mu),&((*M).nu),&((*M).tu));

        (*M).rhead = (OLink *)malloc(((*M).mu + 1)* sizeof(OLink));
        if (!(*M).chead)
            exit(OVERFLOW);
        for (k = 0; k <= (*M).mu; ++k) {
            (*M).rhead[k] = NULL;
        }
        for (k = 0; k <= (*M).nu ; ++k) {
            (*M).chead[k] = NULL;
        }

        for (k = 1; k <= (*M).tu; ++k) {
            p = (OLNode *)malloc(sizeof(OLNode));
            if (!p)
                exit(OVERFLOW);
            Scanf(fp,"%d%d%d",&(p->i),&(p->j),&(p->e));

            p->right = p->down = NULL;

            if ((*M).rhead[p->i] == NULL || (*M).rhead[p->i]->j>p->j) {
                p->right = (*M).rhead[p->i];
                (*M).rhead[p->i] = p;
            } else {
                for (q = (*M).rhead[p->i]; (q->right) && (q->right->j<p->j) ; q = q->right) ;
                if (q->j == p->j || ((q->right) && q->right->j == p->j)) {
                    printf("this place be occupancy");
                    exit(OVERFLOW);
                }
                p->right = q->right;
                q->right = p;
            }

            if ((*M).chead[p->j] == NULL || (*M).chead[p->j]->i > p->i) {
                p->down = (*M).chead[p->j];
                (*M).chead[p->j] = p;
            } else {
                for (q = (*M).chead[p->j]; (q->down) && (q->down->i < p->i)  ; q = q->down);
                if (q->i == p->i || ((q->down) && q->down->i == p->i)){
                    printf("this place has be occupancy");
                    exit(ERROR);
                }
                p->down = q->down;
                q->down = p;
            }
        }
    }
    va_end(ap);
    return OK;
}

void DestorySMatrix_OL(CrossList *M) {
    int i;
    OLNode *p, *q;
    for (i = 1; i <=(*M).mu ; ++i) {
        p = (*M).rhead[i];
        while (p) {
            q = p;
            p = p->right;
            free(q);
        }
    }

    free((*M).rhead);
    free((*M).chead);

    (*M).rhead = (*M).chead = NULL;
    (*M).mu = (*M).nu = (*M).tu = 0;
}

void PrintSMatrix_OL(CrossList M) {
    int i,j;
    OLNode *p;
    for (i = 1; i <= M.mu; ++i) {
        p = M.rhead[i];
        for (j = 1; j <= M.nu; ++j) {
            if (p && p->j == j) {
                printf("%3d",p->e);
                p = p->right;
            } else
                printf("  0");
        }
        printf("\n");
    }
}

void CopySMatrix_OL(CrossList M,CrossList *T) {
    int i;
    OLNode *p,*q,*r,*l;
    T->mu = M.mu;
    T->nu = M.nu;
    T->tu = M.tu;

    T->rhead = (OLink *)malloc((T->mu + 1) * sizeof(OLink));
    if (!T->rhead)
        exit(OVERFLOW);
    for (i = 0; i <= T->mu ; ++i) {
        T->rhead[i] = NULL;
    }
    for (i = 0; i < T->nu; ++i) {
        T->chead[i] = NULL;
    }

    for (i = 1; i <= M.mu; ++i) {
        q = M.rhead[i];
        if (!q)
            continue;
        while (q) {
            p = (OLNode *)malloc(sizeof(OLNode));
            if (!p)
                exit(OVERFLOW);
            p->i = q->i;
            p->j = q->j;
            p->e = q->e;
            p->right = p->down = NULL;
            if (T->rhead[q->i] == NULL)
                T->rhead[q->i] = p;
            else
                r->right = p;
            r = p;
            if (T->chead[q->j] == NULL || T->chead[q->j]->i > q->i) {
                r->down = T->chead[q->j];
                T->chead[q->j] = r;
            } else {
                for (l = T->chead[q->j]; (l->down) && (l->down->i < q->i) ; l=l->down) ;
                r->down = l->down;
                l->down = r;
            }
            q = q->right;
        }
    }
}

Status AddSMatrix_OL(CrossList M,CrossList N,CrossList *Q) {
    int i;
    OLNode *pm,*pn,*p,*r,*l;
    if (M.mu != N.mu || M.nu!=N.nu) {
        printf("cant be add");
        return ERROR;
    }
    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;

    Q->rhead = (OLink *)malloc((Q->mu + 1) * sizeof(OLink));
    if (!Q->rhead)
        exit(OVERFLOW);
    Q->chead = (OLink *) malloc((Q->nu + 1) * sizeof(OLink));
    if (!Q->chead)
        exit(OVERFLOW);
    for (i = 0; i <= Q->mu ; ++i) {
        Q->rhead[i] = NULL;
    }
    for (i = 0; i <= Q->nu ; ++i) {
        Q->chead[i] = NULL;
    }

    for (i = 1; i <= M.mu; ++i) {
        pm = M.rhead[i];
        pn = N.rhead[i];

        while (pm && pn) {
            if (pm->j == pn->j && pm->e + pn->e == 0) {
                pm = pm->right;
                pn = pn->right;
                continue;
            }

            p = (OLNode *)malloc(sizeof(OLNode));
            if (!p)
                exit(OVERFLOW);
            if (pm->j < pn->j) {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pn->e;
                pm = pm->right;
            } else if  (pm->j > pn->j) {
                p->i = pn->i;
                p->j = pn->j;
                p->e = pn->e;
                pn = pn->right;
            } else {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pm->e + pn->e;
                pm = pm->right;
                pn = pn->right;
            }

            p->right = p->down = NULL;
            Q->tu++;

            if (Q->rhead[p->i] == NULL)
                Q->rhead[p->i] = p;
            else
                r->right = p;
            r = p;
            if (Q->chead[p->j] == NULL || Q->chead[p->j]->i>p->i)
            {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                for (l = Q->chead[p->j]; (l->down) && (l->down->i<p->i); l = l->down) ;

                r->down = l->down;
                l->down = r;
            }
        }
        while(pm) {
            p = (OLNode *)malloc(sizeof(OLNode));
            if (!p)
                exit(OVERFLOW);
            p->i = pm->i;
            p->j = pm->j;
            p->e = pm->e;
            p->right = p->down = NULL;

            Q->tu++;

            if (Q->rhead[p->i] == NULL)
                Q->rhead[p->i] = p;
            else
                r->right = p;

            r = p;

            if (Q->chead[p->j] == NULL || Q->chead[p->j]->i>p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                for (l = Q->chead[p->j]; (l->down) && (l->down->i < p->i) ; l = l->down) ;
                r->down = l->down;
                l->down = r;
            }
            pm = pm->right;
        }
        while (pn) {
            p = (OLNode *)malloc(sizeof(OLNode));
            if (!p)
                exit(OVERFLOW);
            p->i = pn->i;
            p->j = pn->j;
            p->e = pn->e;
            p->right = p->down = NULL;

            Q->tu++;

            if (Q->rhead[p->i] == NULL)
                Q->rhead[p->i] = p;
            else
                r->right = p;
            r = p;
            if (Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                for (l = Q->chead[p->j]; (l->down) && (l->down->i < p->i) ;l = l->down) ;
                r->down = l->down;
                l->down = r;
            }
            pn = pn->right;
        }
    }
    return SUCCESS;
}

Status SubSMatrix_OL(CrossList M,CrossList N,CrossList *Q) {
    int i;
    OLNode *pm,*pn,*p,*r,*l;

    if (M.mu != N.mu || M.nu != N.nu) {
        printf("can't be sub");
        return ERROR;
    }

    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;

    Q->rhead = (OLink *)malloc((Q->mu + 1) * sizeof(OLink));
    if (!Q->rhead)
        exit(OVERFLOW);
    Q->chead = (OLink *)malloc((Q->nu + 1) * sizeof(OLink));
    if (!Q->chead)
        exit(OVERFLOW);
    for (i = 0; i <= Q->mu; ++i) {
        Q->rhead[i] = NULL;
    }

    for (i = 0; i <= Q->nu ; ++i) {
        Q->chead[i] = NULL;
    }

    for (i = 1; i <= M.mu; ++i) {
        pm = M.rhead[i];
        pn = N.rhead[i];

        while (pm && pn) {
            if (pm->j == pn->j && pm->e - pn->e == 0) {
                pm = pm->right;
                pn = pn->right;
                continue;
            }

            p = (OLNode *) malloc(sizeof(OLNode));

            if (!p)
                exit(OVERFLOW);

            if (pm->j < pn->j) {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pm->e;
                pm = pm->right;
            } else if (pm->j > pn->j) {
                p->i = pm->i;
                p->j = pn->j;
                p->e = -pn->e;
                pn = pn->right;
            } else {
                p->i = pm->i;
                p->j = pm->j;
                p->e = pm->e - pn->e;
                pm = pm->right;
                pn = pn->right;
            }
            
            p->right = r->down = NULL;
            
            Q->tu++;
            
            if (Q->rhead[p->i] == NULL)
                Q->rhead[p->i] = p;
            else
                r->right = p;
            r = p;
            
            if (Q->chead[p->j] == NULL || Q->chead[p->j]->i>p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                for (l = Q->chead[p->j]; (l->down) && (l->down->i < p->i) ; l = l->down) ;
                r->down = l->down;
                l->down = r;
            }
        }
        while (pm) {
            p = (OLNode *)malloc(sizeof(OLNode));
            if (!p)
                exit(OVERFLOW);
            p->i = pm->j;
            p->j = pm->j;
            p->e = pm->e;
            p->right = p->down = NULL;
            
            Q->tu++;
            
            if (Q->rhead[p->i] == NULL)
                Q->rhead[p->i] = p;
            else
                r->right = p;
            r = p;
            if (Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                for (l=Q->chead[p->j];(l->down) && (l->down->i < p->i);l = l->down) ;
                r->down = l->down;
                l->down = r;
            }
            pm = pm->right;
        }
        while (pn) {
            p = (OLNode *)malloc(sizeof(OLNode));
            if (!p)
                exit(OVERFLOW);
            p->i = pn->i;
            p->j = pn->j;
            p->e = -pn->e;
            p->right = pn->down = NULL;
            
            Q->tu++;
            if (Q->rhead[p->i] == NULL)
                Q->rhead[p->i] = p;
            else 
                r->right = p;
            
            r = p;
            
            if (Q->rhead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                r->down = Q->chead[p->j];
                Q->chead[p->j] = r;
            } else {
                for (l = Q->chead[p->j];(l->down) && (l->down->i < p->i);l = l->down) ;
                r->down = l->down;
                l->down = r;
            }
            pn = pn->right;
        }
    }
    return SUCCESS;
}

Status MultiSMatrix_OL(CrossList M,CrossList N,CrossList *Q) {
    int m_row,n_col,i;
    CELemType e;
    OLNode *pm,*pn,*p,*r,*l;

    if (M.nu != N.mu) {
        printf("cant be multi");
        return  ERROR;
    }

    Q->mu = M.mu;
    Q->nu = M.nu;
    Q->tu = 0;

    Q->rhead = (OLink *)malloc((Q->mu + 1) * sizeof(OLink));
    if (!Q->rhead)
        exit(OVERFLOW);
    Q->chead = (OLink *)malloc((Q->nu + 1) * sizeof(OLink));
    if (!Q->chead)
        exit(OVERFLOW);
    for (i = 0; i <= Q->mu; ++i) {
        Q->rhead [i] = NULL;
    }

    for (i = 0; i <= Q->nu ; ++i) {
        Q->chead [i] = NULL;
    }

    if (M.tu * N.tu) {
        for (m_row = 1; m_row <= M.mu ; ++m_row) {
            for (n_col = 1; n_col <= N.nu ; ++n_col) {
                pm = M.rhead[m_row];
                pn = N.chead[n_col];
                e = 0;

                while (pm && pn) {
                    pm = M.rhead[m_row];
                    pn = N.chead[n_col];
                    e = 0;

                    while (pm && pn) {
                        if (pm->j < pn->j)
                            pm = pm->right;
                        else if (pm->j > pn->j)
                            pn = pn->down;
                        else {
                            e += pm->e * pn->e;
                            pm = pm->right;
                            pn = pn->down;
                        }
                    }
                    if (e) {
                        p = (OLNode *)malloc(sizeof(OLNode));
                        if (!p)
                            exit(OVERFLOW);
                        p->i = M.rhead[m_row]->i;
                        p->j = N.chead[n_col]->j;
                        p->e = e;
                        p->right = p->down =NULL;

                        Q->tu++;

                        if (Q->rhead[p->i] == NULL)
                            Q->rhead[p->i] = p;
                        else
                            r->right = p;
                        r = p;

                        if (Q->chead[p->j] == NULL || Q->chead[p->j]->i > p->i) {
                            r->down = Q->chead[p->j];
                            Q->chead[p->j] = r;
                        } else {
                            for (l = Q->chead[p->j];(l->down) && (l->down->i < p->i);l = l->down) ;
                            r->down = l->down;
                            l->down = r;
                        }
                    }
                }
            }
        }
    }
    return OK;
}

void TransposeSMatrix_OL(CrossList M,CrossList *T) {
    int i;
    OLNode *p,*q,*r,*l;
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;

    T->rhead = (OLink *)malloc((T->mu + 1) * sizeof(OLink));
    if (!T->rhead)
        exit(OVERFLOW);
    for (i = 0; i <= T->mu ; ++i) {
        T->rhead[i] = NULL;
    }

    for (i = 0; i <= T->nu; ++i) {
        T->chead[i] = NULL;
    }

    if (T->tu) {
        for (i = 1; i <= M.nu; ++i) {
            q = M.chead[i];
            if (!q)
                continue;

            while (q) {
                p = (OLNode *) malloc(sizeof(OLNode));
                if (!p)
                    exit(OVERFLOW);
                p->i = q->j;
                p->j = q->i;
                p->e = q->e;
                p->right = q->down = NULL;

                if (T->rhead[p->i] == NULL)
                    T->rhead[p->i] = p;
                else
                    r->right = p;

                r = p;
                if (T->chead[p->j] == NULL || T->chead[p->j]->i > p->i) {
                    r->down = T->chead[p->j];
                    T->chead[p->j] = r;
                } else {
                    for (l = T->chead[p->j]; (l->down) && (l->down->i < p->i); l = l->down);
                    r->down = l->down;
                    l->down = r;
                }
                q = q->down;
            }

        }
    }
}

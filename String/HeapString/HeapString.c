//
// Created by 张一鸣 on 16/8/11.
//

#include "HeapString.h"


void InitString_H(HString *S) {
    (*S).ch =NULL;

    (*S).length = 0;
}

Status StrAssign_H(HString *T, char *chars) {
    int i,j;
    InitString_H(T);

    i = strlen(chars);

    if (!i)
        return ERROR;
    else
    {
        (*T).ch = (char *)malloc(i* sizeof(chars));

        if (!((*T).ch))
            exit(OVERFLOW);
        for (j = 0; j < i ; j++) {
            (*T).ch[j] = chars[j];
        }

        (*T).length = i;
    }
    return OK;
}

Status StrCopy_H(HString *T,HString S) {
    int i;
    InitString_H(T);

    if (StrLength_H(S))
        return ERROR;

    (*T).ch = (char *)malloc(S.length* sizeof(char));

    if (!(*T).ch)
        exit(OVERFLOW);

    for (i = 0; i < S.length; ++i) {
        (*T).ch[i] = S.ch[i];
    }

    (*T).length = S.length;

    return OK;
}

Status StrEmpty(HString s) {
    if (s.length == 0 && s.ch == NULL)
        return TRUE;
    else
        return FALSE;
}

Status StrCompare_H(HString S,HString T) {
    int i;
    for ( i = 0; i < S.length && i < T.length; ++i) {
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length-T.length;
}

int StrLength_H(HString S) {
    if (StrEmpty(S))
        return 0;
    else
        return S.length;
}

Status ClearString_H(HString *S) {
    if((*S).ch) {
        free((*S).ch);
        (*S).ch = NULL;
    }

    (*S).length = 0;
    return OK;
}

Status Concat_H(HString *T,HString S1,HString S2) {
    int i;
    InitString_H(T);

    (*T).length = S1.length + S2.length;

    (*T).ch = (char *)malloc((*T).length* sizeof(char));
    if (!(*T).ch)
        exit(OVERFLOW);
    for (i = 0; i < S1.length; ++i) {
        (*T).ch[i] = S1.ch[i];
    }

    for (i = 0; i < S2.length; ++i) {
        (*T).ch[S1.length + i] = S2.ch[i];
    }

    return OK;
}

Status SubString_H(HString *Sub,HString S, int pos, int len) {
    int i;
    InitString_H(Sub);
    if (StrEmpty(S))
        return ERROR;

    if (pos < 1|| pos>S.length || len<0||pos+len-1>S.length)
        return ERROR;

    if (len) {
        (*Sub).ch = (char *)malloc(len * sizeof(char));
        if (!(*Sub).ch)
            exit(OVERFLOW);

        for ( i = 0; i < len; ++i) {
            (*Sub).ch[i] = S.ch[i+pos-1];
        }
        (*Sub).length = len;
    }
    return OK;
}

int Index_H(HString S,HString T, int pos) {
    int s,t,i;
    HString Sub;
    InitString_H(&Sub);

    if (pos>0) {
        s = S.length;
        t = T.length;
        i = pos;

        while(i + t - 1 <= s) {
            SubString_H(&Sub,S,i,t);
            if (StrCompare_H(Sub,T))
                i++;
            else
                return i;
        }
    }
    return 0;
}

Status Replace_H(HString *S,HString T,HString V) {
    int i;
    if (StrEmpty(T))
        return ERROR;
    i = Index_H(*S,T,1);
    while (i != 0) {
        StrDelete_H(S,i,StrLength_H(T));
        StrInsert_H(S,i,V);
        i += StrLength_H(V);
        i = Index_H(*S,T,i);
    }
    return OK;
}

Status StrInsert_H(HString *S, int pos, HString T) {
    int i;
    if (pos<1 || pos>(*S).length+1)
        return ERROR;

    if (StrEmpty(T))
        return ERROR;
    else {
        (*S).ch = (char *)realloc((*S).ch,((*S).length + T.length)* sizeof(char));

        if (!(*S).ch)
            exit(OVERFLOW);

        for (i = (*S).length - 1 ; i >= pos - 1  ; i-- ) {
            (*S).ch[i+T.length] = (*S).ch[i];
        }

        for (i = 0; i < T.length; ++i) {
            (*S).ch[pos + i] = T.ch[i];
        }
        (*S).length += T.length;
    }

    return OK;
}

Status StrDelete_H(HString *S, int pos, int len) {
    int i;
    if (StrEmpty(*S))
        return ERROR;
    if (pos < 1 || pos + len - 1>(*S).length ||len < 0)
        return ERROR;

    for (i = pos-1; i + len <= (*S).length  ; i++) {
        (*S).ch[i] = (*S).ch[i+len];
    }
    (*S).length -= len;
    (*S).ch = (char *)realloc((*S).ch,(*S).length * sizeof(char));
    return OK;
}

void DestoryString_H(HString *S) {

}

void StrPrint_H(HString S) {
    int i;
    if (StrEmpty(S))
        printf("S为空");

    for (i = 0; i < S.length; ++i) {
        printf("%c",S.ch[i]);
    }
}

//
//  Union.c
//  LinearListUnion
//
//  Created by akka on 16/7/1.
//  Copyright © 2016年 akka. All rights reserved.
//

#include "Union.h"

void Union(SqList *La,SqList Lb) {
    int La_len ,Lb_len;
    int i;
    LElementType_Sq e;
    
    La_len = ListLength_Sq(*La);
    Lb_len = ListLength_Sq(Lb);
    
    for (i = 1; i <= Lb_len; i++) {
        GetElem_Sq(Lb, i, &e);
        if (!LocateElem_Sq(*La, e, equal)) {
            ListInsert_Sq(La, ++La_len, e);
        }
    }
}

Status equal(LElementType_Sq e1,LElementType_Sq e2) {
    return e1 == e2 ? TRUE : FALSE;
}
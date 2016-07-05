//
//  MergeList.c
//  MergeLinkList
//
//  Created by akka on 16/7/4.
//  Copyright © 2016年 akka. All rights reserved.
//

#include "MergeList.h"

void MergeList_L(LinkList La,LinkList *Lb,LinkList *Lc) {
    LinkList pa,pb,pc;
    pa = La->next;
    pb = (*Lb)->next;
    pc = *Lc = La;
    
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    
    pc->next = pa ? pa:pb;
    free(*Lb);
    *Lb = NULL;
}
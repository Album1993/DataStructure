//
//  main.c
//  LinearList
//
//  Created by akka on 16/6/29.
//  Copyright © 2016年 akka. All rights reserved.
//

#include <stdio.h>
#include "List.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    Lista * l = GlobalList();
    int i,j = 4;
    
    for (i=0; i < 5; i++) {
        inserir(l, i*j);
    }
    
    printf("list complete\n");
    printer(l);
    remover(l,j);
    
    printf("\n lsita");
    
    printer(l);

    return 0;
}

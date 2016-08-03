//
//  main.m
//  SequenceStack
//
//  Created by akka on 16/8/3.
//  Copyright © 2016年 akka. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SequenceStack.h"

void PrintElem(SElemType_Sq e) {
    printf("%d\n",e);
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        SqStack S;
        int i;
        SElemType_Sq e;
        
        InitList_Sq(&S);
        
        for (i = 1; i<=6; i++) {
            Push_sq(&S, 2*i);
        }
        StackTraverse_Sq(S, PrintElem);
        
        GetTop_Sq(S, &e);
        printf("顶部元素：%d",e);
        
        Pop_Sq(&S, &e);
        
        NSLog(@"pop:%d",e);
        
        Pop_Sq(&S, &e);
        
        NSLog(@"pop:%d",e);
        
    }
    return 0;
}


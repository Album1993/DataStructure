//
//  Status.h
//  LinearList
//
//  Created by akka on 16/6/30.
//  Copyright © 2016年 akka. All rights reserved.
//

#ifndef Status_h
#define Status_h

#define TRUE        1
#define FALSE       0
#define YES         1
#define NO          0
#define OK          1
#define NO          0
#define ERROR       0
#define SUCCESS     1
#define UNSUCCESS   0
#define INFEASIBIE  -1

#ifndef _MATH_H
#define OVERFLOW    -2
#define UNDERFLOW   -3
#endif

#ifndef NULL
#define NULL    ((void*)0)
#endif

typedef int Status;

#define Wait(x)\
{\
    double _Loop_Num_;\
    for(_Loop_Num_=0.01;__Loop_Num_<=100000.0 * x;_Loop_num_+=0.01)\
        ;\
}

#define PressEnter \
{\
    fflush(stdin);\
    printf("Press Enter...");\
    getchar();\
    fflush(stdin);\
}

#endif /* Status_h */

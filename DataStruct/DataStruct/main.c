//
//  main.c
//  DataStruct
//
//  Created by MAMIAN on 2016/12/15.
//  Copyright © 2016年 Gaofei Ma. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[5] = {10, 20, 30, 40, 50};
    int *aPtr = &a[0];
    int *bPtr = &a[2];
    long num = aPtr - bPtr;
    printf("num = %ld\n", num);
    return 0;
}

//
//  main.c
//  page33_数组指针
//
//  Created by MAMIAN on 2016/12/16.
//  Copyright © 2016年 Gaofei Ma. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int (*p)[4];
    int row, col;
    p = a;
    
    // 打印输出数组指针p指向的数组的值
    for (row = 0; row < 3; row++) {
        for (col=0; col<4; col++) {
            printf("a[%d,%d]=%-4d", row, col, *(*(p+row)+col));
        }
        printf("\n");
    }
    
    // 通过改变指针p修改数组a的行地址，改变col的值修改数组a的列地址
    for (p=a,row=0; p<a+3; p++, row++) {
        for (col=0; col<4; col++) {
            printf("(*p[%d])[%d] = %p", row, col, ((*p)+col));
        }
        printf("\n");
    }
    
    
    
    
    return 0;
}

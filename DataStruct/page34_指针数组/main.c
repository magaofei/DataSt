//
//  main.c
//  page34_指针数组
//
//  Created by MAMIAN on 2016/12/16.
//  Copyright © 2016年 Gaofei Ma. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char *book[4] = {"C Programming Language", "Assembly Language",
        "Java Language", "Natural Language"};
    int n = 4;
    int row;
    char *arrayPtr;
    // 第一种方法 通过数组名输出
    printf("通过指针数组中的各个数组名输出\n");
    for (row=0; row<n; row++) {
        printf("第%d个字符串:%s\n", row+1, book[row]);
    }
    
    // 第二种方法 通过指向数组的指针输出
    printf("通过指向数组的指针输出\n");
    for (arrayPtr=book[0],row=0; row<n; arrayPtr=book[row]) {
        printf("第%d个字符串：%s\n",row+1, arrayPtr);
        row++;
    }
    
    return 0;
}

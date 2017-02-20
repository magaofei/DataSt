//
//  main.c
//  DataStruct
//
//  Created by MAMIAN on 2016/12/19.
//  Copyright © 2016年 Gaofei Ma. All rights reserved.
//  是一个函数的指针, 指向一个函数

#include <stdio.h>
int sum (int a, int b);

int main() {
    int a,b;
    int (*fun)(int ,int ); //函数指针
    printf("请输入两个数,以逗号相隔：");
    scanf("%d,%d",&a,&b);
    
    // 调用函数的方法，
    printf("调用函数的方法\n");
    printf("%d+%d=%d\n", a, b, sum(a,b));
    
    // 通过函数指针
    fun = sum;
    printf("通过函数指针\n");
    printf("%d+%d=%d\n", a, b, (*fun)(a,b));
}

int sum(int m, int n) {
    return m+n;
}

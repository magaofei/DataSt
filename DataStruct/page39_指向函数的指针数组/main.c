//
//  main.c
//  page39_指向函数的指针数组
//
//  Created by MAMIAN on 2016/12/22.
//  Copyright © 2016年 Gaofei Ma. All rights reserved.
//

#include <stdio.h>

void f1();
void f2();
void f3();


int main(int argc, const char * argv[]) {
    // insert code here...
    
    void (*f[3])() = {f1, f2, f3};  // 指向函数的指针数组的声明
    int flag;
    printf("请输入一个1,2,或者3,输入0退出\n");
    
    scanf("%d", &flag);
    while (flag) {
        if (flag == 1 || flag == 2 || flag == 3) {
            f[flag-1](flag-1);   //通过函数指针调用数组中的函数
            printf("请输入一个1,2,或者3,输入0退出\n");
            scanf("%d", &flag);
        } else {
            printf("请输入一个合法的数(1-3),0退出.\n");
            scanf("%d", &flag);
        }
    }
    printf("程序退出\n");

    return 0;
}

void f1() {
    printf("函数f1 被调用\n");
}

void f2() {
    printf("函数f2 被调用\n");

}

void f3() {
    printf("函数f3 被调用\n");
    
}

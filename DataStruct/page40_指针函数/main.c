//
//  main.c
//  page40_指针函数
//
//  Created by MAMIAN on 2016/12/22.
//  Copyright © 2016年 Gaofei Ma. All rights reserved.
//  首先是一个函数, 其次返回相应类型的指针

#include <stdio.h>

int *FindAddress(int (*ptr)[4], int n);   // 声明查找成绩行地址函数
void Display(int a[][4], int n, int *p);   //声明输出成绩函数

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int row, n=4;
    int *p;
    int score[3][4] = {{76,87,85,81}, {67,61,71,60}, {81,89,82,78}};
    printf("请输入学生编号(1或2或3). 输入0退出程序\n");
    scanf("%d", &row);
    while (row) {
        if (row == 1 || row == 2 || row == 3) {
            printf("第%d个学生的4门课的成绩是:\n", row);
            p = FindAddress(score, row-1);  //调用指针函数
            Display(score, n, p);  // 调用输出成绩函数
            printf("请输入学生编号(1或2或3). 输入0退出程序\n");
            scanf("%d", &row);
            
        } else {
            printf("输入不合法, 重新输入学生编号(1或2或3). 输入0退出程序\n");
            scanf("%d", &row);
        }
    }
    
    return 0;
}

int* FindAddress(int (*ptrScore)[4], int n) {
    // 查找学生成绩行地址函数的实现, 通过传递的行地址找到要查找学生成绩的地址, 并返回行地址
    int *ptr;
    ptr = *(ptrScore + n);
    return ptr;
}

void Display(int a[][4], int n, int *p) {
    // 输出学生成绩的实现函数, 利用传递过来的指针输出每门课的成绩
    int col;
    for (col = 0; col < n; col++) {
        printf("%4d", *(p+col));   // 输出查找学生的每门课成绩
    }
    printf("\n");
}

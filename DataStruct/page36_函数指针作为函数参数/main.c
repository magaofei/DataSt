//
//  main.c
//  page36_函数指针作为函数参数
//
//  Created by MAMIAN on 2016/12/19.
//  Copyright © 2016年 Gaofei Ma. All rights reserved.
//

#include <stdio.h>
#define N 10  //数组元素个数
int Ascending(int a, int b);  // 是否进行升序排列的函数声明
int Descending(int a, int b);// 是否进行降序排列的函数声明
void swap(int *,int *);  //交换数据的函数声明
void BubbleSort(int a[], int n, int (*compare)(int ,int ));  //声明排序函数，通过函数指针作为参数调用
void Display(int a[], int n);  // 输出数组元素的函数声明


int main(int argc, const char * argv[]) {
    int a[N] = {12, 34, 21, 46, 89, 54, 26, 8, 6, 17};
    int flag;
    while (1) {
        printf("输入1：从小到大排序\n，输入2:从大到小排列\n输入3:退出\n");
        scanf("%d",&flag);
        switch (flag) {
            case 1:
                printf("排序前的数据为：");
                Display(a, N);
                BubbleSort(a, N, Ascending);
                printf("从小到大排列后的数据为");
                Display(a, N);
                break;
            case 2:
                printf("排序前的数据为:");
                Display(a, N);
                BubbleSort(a, N, Descending);
                printf("从大到小排列后的数据为");
                Display(a, N);
                break;
            case 3:
                return 0;
                break ;
            default:
                printf("输入数据不合法,请重新输入\n");
                break;
        }
    }
    return 0;
}

// 冒泡排序,将函数作为参数传递, 判断是
void BubbleSort(int a[], int n, int (*compare)(int , int )) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1; j++) {
            if ((*compare)(a[j], a[j+1])) {  // 此处返回1/0, 判断大小
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

/* 判断相邻数据大小,如果前者大,降序排列需要更换 */
int Ascending(int a, int b) {
    if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

int Descending(int a, int b) {
    if (a < b) {
        return 1;
    } else {
        return 0;
    }
}

void Display(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%4d", a[i]);
    }
    printf("\n");
}



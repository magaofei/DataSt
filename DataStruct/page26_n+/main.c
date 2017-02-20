//
//  main.c
//  page26_n+
//
//  Created by MAMIAN on 2016/12/15.
//  Copyright © 2016年 Gaofei Ma. All rights reserved.
//

#include <stdio.h>
#define N 50
int sum(int a[], int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    int i, n, a[N];
    printf("请输入一个自然数\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        a[i] = i+1;  //将数填入到数组内
    }
    
    printf("前%d个自然数的和为：%d\n", n, sum(a, n));
    return 0;
}

int sum(int a[], int n) {
    if (n <= 0) {
        return 0;
    } else {
        return a[n-1] + sum(a, n-1);
    }
}

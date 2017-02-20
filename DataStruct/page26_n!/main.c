//
//  main.c
//  page26_n!
//
//  Created by MAMIAN on 2016/12/15.
//  Copyright © 2016年 Gaofei Ma. All rights reserved.
//

#include <stdio.h>
long factorial(int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    int num;
    for (num = 0; num < 10; num++) {
        printf("%d=%ld\n", num, factorial(num));
    }
    
    
    return 0;
}

long factorial(int n) {
    if (n == 0) {   //递归结束条件  0！== 1
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

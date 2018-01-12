//
//  main.m
//  page57_1回文
//
//  Created by MAMIAN on 2017/2/28.
//  Copyright © 2017年 Gaofei Ma. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <string.h>

int main(int argc, const char * argv[]) {
    char arr[100];
    printf("请输入一个字符串\n");
    scanf("%s", arr);
    
    int n = strlen(arr);
    int start = 0, end = n - 1;
    
    
    while (start<end) {
        char startChar = arr[start];
        char endChar = arr[end];
        if (strcmp(&startChar, &endChar) == 0) {
            start++;
            end--;
        } else {
            break;
        }
    }
    
    if (start == end) {
        printf("是回文");
    } else {
        printf("不是");
    }
    return 0;
}

//
//  main.c
//  DataStruct
//
//  Created by MAMIAN on 2018/1/12.
//  Copyright © 2018年 Gaofei Ma. All rights reserved.
//

#include <stdio.h>

int binary_search(int key, int arr[], int start, int end) {
    /*
     二分查找
     要求,一定是顺序排列
     
     */
    
    if (start > end) return -1;
    int mid = start + (end - start) / 2;
    
    if (arr[mid] > key) {
        return binary_search(key, arr, start, mid - 1);
    } else if (arr[mid] < key) {
        return binary_search(key, arr, mid + 1, end);
        
    } else {
        return mid;
    }
    
}


int main(int argc, const char * argv[]) {
    int arr[5] = {1, 2, 3, 4, 5};
    int key = 3;
    int value = binary_search(key, arr, 1, 5);
    printf("%d\n", value);
    return 0;
}




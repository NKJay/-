//
//  main.c
//  mergeSort
//
//  Created by NKJay on 2017/3/2.
//  Copyright © 2017年 NKJay. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int printString(int a[100]);
int merge(int num[100],int lo,int hi, int mid);
int sort(int a[100],int lo, int hi);

int main(int argc, const char * argv[]) {
    
    int length = 10;
    int num[100] = {2,4,3,1,5,8,0,7,9,6};
    sort(num, 0, length - 1);
    printString(num);
    return 0;
}

/*
 归并函数
 主要原理在于对两个数组的第一个数进行比较并把较小的那个放入原数组，如果其中一个需要归并的数组归并完成则将两一个数组剩余数直接按序拷贝到原数组后
 @param num 需要排序的数组
 @param lo 最小下标
 @param hi 最大下标
 @param mid 中间下标
 */
int merge(int num[100],int lo,int hi, int mid){
    
    int j = mid + 1;
    int i = lo;
    //创建新数组并拷贝存放原来的数组
    int aux[100];
    for (int n = 0; n <= hi; n++ ) {
        aux[n] = num[n];
        printf("%d ",num[n]);
    }
    printf("\n");
    
    //归并两个数组并
    for (int k = lo; k <= hi; k++) {
        //判断如果其中一个数组已归并完成则将两一个数组按序归并到原数组
        if (i > mid) {
            num[k] = aux[j++];
        }else if(j > hi){
            num[k] = aux[i++];
//        判断两个数大小，并把小的数放在原数组中
        }else if(aux[j] < aux[i]){
            num[k] = aux[j++];
        }else{
            num[k] = aux[i++];
        }
    }
    
    return 0;
}
//排序函数，参数同上
int sort(int a[100],int lo, int hi){
//    判断如果最小下标大于等于最大下标则返回
    if (lo >= hi) {
        return 0;
    }
    int mid = (hi + lo) / 2;
    //递归调用函数分别排序左右两边数组
    sort(a,lo,mid);
    sort(a,mid+1,hi);
    //将排序后的左右数组归并
    merge(a, lo, hi, mid);
    return 0;
}
//自定义方法，用于输出数组内容
int printString(int num[100]){
    for (int i = 0; i < 10; i++) {
        printf("%d ",num[i]);
    }
    printf("\n");
    return 0;
}

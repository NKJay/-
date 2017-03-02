//
//  main.c
//  QuickSort
//
//  Created by NKJay on 2017/3/2.
//  Copyright © 2017年 NKJay. All rights reserved.
//

#include <stdio.h>

int printString(int num[100]);
int swap(int *a,int *b);
int quickSort(int num[100],int lo,int hi);

int main(int argc, const char * argv[]) {
    int length = 10;
    int num[100] = {8,4,3,1,5,8,0,7,9,6};
    quickSort(num, 0, length - 1);
    printString(num);
    return 0;
}
/*
 快速排序
 @param num 要排序的数组
 @param lo 最小下标
 @param hi 最大下标
 */
int quickSort(int num[100],int lo,int hi){
    
    if (lo >= hi) {
        return 0;
    }
    
    int i = lo,j = hi;
    //将第一个值作为判断参考值
    int q = num[lo];
    
    //如果左标记与右标记不相遇则一直循环
    while (j != i) {
        //如果右标记遇到小于标记数的数则停止
        //注意1：要判断左标记需要大于右标记否则可能出现无限循环，切一定要大于等于，少了等于也会出现无限循环
        //注意2：从哪边选择的参考数就要从另一边先开始遍历，否则从基准数一方先开始遍历，那么会丢失基准数，当只剩2个数需要排序时，从基准数一方开始的话就会2个数无限循环交换
        if (num[j] >= q && j > i) j--;
        //如果左标记遇到大于标记数的数则停止
        if (num[i] <= q && j > i) i++;
        //将左右标记所对应的数交换位置
        if (j > i) {
            swap(&num[i], &num[j]);
        }
    }
    //此时左标记i和右标记j相等，且标记数左边都比标记数小右边都比标记数大，将标记数与参考数交换位置，此时参考数已在数组正确位置
    swap(&num[lo], &num[j]);
    //分别排序标记左右两边的数组
    quickSort(num, lo, i);
    quickSort(num, i + 1, hi);
    return 0;

}

//用于输出数组内容
int printString(int num[100]){
    for (int i = 0; i < 10; i++) {
        printf("%d ",num[i]);
    }
    printf("\n");
    return 0;
}
//指针交换函数
int swap(int *a,int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
    return 0;
}

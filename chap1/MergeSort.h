#include <iostream>
#include "ImprovedInsertSort.h"

template<typename T>
void merge(T arr[], int l, int mid, int r){
    // 将arr[l,...,mid] 和 arr[mid+1,...,r]归并

    // 复制一份arr
    T *brr = new T[r-l+1];
    for(int i=0;i<r-l+1;i++){
        brr[i] = arr[i+l];
    }

    int i = l;
    int j = mid+1;
    for(int k=l;k<=r;k++){
        if(i>mid){// 左半部分已经遍历结束
            arr[k] = brr[j-l];
            j++;
        }else if(j>r){// 右半部分已经遍历结束
            arr[k] = brr[i-l];
            i++;
        }else if(brr[i-l] < brr[j-l]){//左半部分所指元素 < 右半部分所指元素
            arr[k] = brr[i-l];
            i++;
        }else{// 左半部分所指元素 >= 右半部分所指元素
            arr[k] = brr[j-l];
            j++;
        }
    }
    delete[] brr;
}

// 递归使用归并排序，对arr[l,...,r]进行排序
template<typename T>
void mergeSort(T arr[], int l, int r){
    /*    
    // 边界情况：l == r
    if(l>=r){
        return;
    }
    */
    
    if(r-l<=15){// 数组只剩16个元素时，使用插入排序
        ImprovedInsertSort(arr,l,r);
        return;
    }
    
    // 对数组两侧分别排序
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    
    // 两侧排序后，归并arr[l,...,mid] 和arr[mid+1,...,r]
    if(arr[mid] > arr[mid+1])//此时才需要归并
        merge(arr,l,mid,r);
}

template<typename T>
void mergeSort(T arr[],int n){
    mergeSort(arr,0,n-1);
}


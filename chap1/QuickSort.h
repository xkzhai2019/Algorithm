#include <iostream>
#include "ImprovedInsertSort.h"

// 对arr[l,...,r]进行分割，分割为三部分
// 返回j，使得arr[l,...,j-1] < arr[j];  arr[j+1,...,r]> arr[j]
template<typename T>
int __partition(T arr[],int l,int r){
    // 随机选取基准元素
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    int j = l; // arr[l+1,...,j]< v; arr[j+1,...,i-1]>v
    for(int i=l+1;i<=r;i++){
        if(arr[i]<v){
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    swap(arr[l],arr[j]);
    return j;
}


// 对arr[l,...,r]进行快速排序
template<typename T>
void __QuickSort(T arr[], int l, int r){
    /*
    if(l>=r)
        return;
    */
    if(r-l<=15){
        ImprovedInsertSort(arr,l,r);
        return;
    }
    int j = __partition(arr,l,r);
    __QuickSort(arr,l,j-1);
    __QuickSort(arr,j+1,r);
}

template<typename T>
void QuickSort(T arr[], int n){
    srand(time(NULL));
    __QuickSort(arr,0,n-1);
}

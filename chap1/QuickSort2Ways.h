#include <iostream>
#include "ImprovedInsertSort.h"
using namespace std;

// 对arr[l,...,r]进行分割，分割为三部分
// 返回p，使得arr[l,...,p-1] <= arr[p];  arr[p+1,...,r]=> arr[p]
template<typename T>
int __partition2(T arr[],int l,int r){
    // 随机选取基准元素
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];

    int i = l+1; // arr[l+1,...,i-1]<=v
    int j = r; // arr[j+1,...,r]>=v
    while(true){
        while(i<=r && arr[i]<v)
            i++;
        while(j>=l+1 && arr[j]>v)
            j--;

        if(i>j) break;
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    swap(arr[l],arr[j]);
    return j;
}


// 对arr[l,...,r]进行双路快速排序
template<typename T>
void __QuickSort2(T arr[], int l, int r){
    /*
    if(l>=r)
        return;
    */
    if(r-l<=15){
        ImprovedInsertSort(arr,l,r);
        return;
    }
    // 调用双路快速排序的分割方法
    // 返回j,满足arr[l,...,j-1]<=arr[j]; arr[j+1,...,r]>=arr[j]
    int j = __partition2(arr,l,r);
    __QuickSort2(arr,l,j-1);
    __QuickSort2(arr,j+1,r);
}

template<typename T>
void QuickSort2Ways(T arr[], int n){
    srand(time(NULL));
    __QuickSort2(arr,0,n-1);
}

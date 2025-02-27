#ifndef IMPROVEDINSERTSORT_H
#define IMPROVEDINSERTSORT_H
#include <iostream>

template<typename T>
void ImprovedInsertSort(T arr[],int n){
    for(int i=1;i<n;i++){
        // 寻找arr[i]合适的插入位置
        T tmp = arr[i];
        int j = i;
        for(;j>0;j--){
            if(arr[j-1]>tmp){
                arr[j] = arr[j-1];
            }else{
                break;
            }
        }
        arr[j] = tmp;
    }
}
// 对arr[l,...,r]进行插入排序
template<typename T>
void ImprovedInsertSort(T arr[],int l,int r){
    for(int i=l+1;i<=r;i++){
        // 寻找arr[i]合适的插入位置
        T tmp = arr[i];
        int j = i;
        for(;j>l;j--){
            if(arr[j-1]>tmp){
                arr[j] = arr[j-1];
            }else{
                break;
            }
        }
        arr[j] = tmp;
    }
}

#endif

#include <iostream>
#include "SortTools.h"
#include "BubbleSort.h"
#include "SelectSort.h"

template<typename T>
void merge(T arr[], int l, int mid, int r){
    // 将arr[l,...,mid] 和 arr[mid+1,...,r]归并
    SortTools::printArr(arr+l,r-l+1);
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
    // 边界情况：l == r
    if(l>=r){
        return;
    }

    /*
    if(r-l<=15){// 数组只剩16个元素时，使用插入排序
        ImprovedInsertSort(arr,l,r);
        return;
    }
    */
    
    // 对数组两侧分别排序
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    
    // 两侧排序后，归并arr[l,...,mid] 和arr[mid+1,...,r]
    if(arr[mid] > arr[mid+1]){//此时才需要归并
        merge(arr,l,mid,r);
    }
}

template<typename T>
void mergeSort(T arr[],int n){
    mergeSort(arr,0,n-1);
}

template<typename T>
void mergeSortBU(T arr[],int n){
    for(int sz=1; sz<=n/2; sz *= 2){// 每次以sz个元素为一组进行归并，sz从1开始
        for(int i=0;i<n;i += 2*sz){ // 0～sz-1 和 sz～2*sz-1 
                                    // 2*sz~3*sz-1 和 3*sz ~ 4*sz-1
            merge(arr,i,i+sz-1,i+2*sz-1);
        }
    }
}



int main(void){
    int a[] = {8,6,3,2,1,7,5,4};
    SortTools::printArr(a,8);
    mergeSort(a,8);
    std::cout<<"--------------"<<std::endl;
    int b[] = {8,6,3,2,1,7,5,4};
    SortTools::printArr(b,8);
    mergeSortBU(b,8);
	return 0;
}

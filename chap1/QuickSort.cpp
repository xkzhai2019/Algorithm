#include <iostream>
#include "SortTools.h"
#include "BubbleSort.h"
#include "SelectSort.h"
#include "HFInsertSort.h"
#include "ImprovedInsertSort.h"
#include "MergeSort.h"

// 对arr[l,...,r]进行分割，分割为三部分
// 返回j，使得arr[l,...,j-1] < arr[j];  arr[j+1,...,r]> arr[j]
template<typename T>
int __partition(T arr[],int l,int r){
    // 基准元素
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
    __QuickSort(arr,0,n-1);
}

int main(void){
    int N = 50000;
    int *arr = SortTools::generateRandomArr(N,0,100000);
    int *brr = SortTools::generateRandomArr(N,0,100000);
    int *crr = SortTools::generateRandomArr(N,0,100000);
    int *drr = SortTools::generateRandomArr(N,0,100000);
    int *err = SortTools::generateRandomArr(N,0,100000);
    int *frr = SortTools::generateRandomArr(N,0,100000);

    std::cout<<"RandomArr: "<< N<<std::endl;
    SortTools::testSort("Bubble Sort",BubbleSort,arr,N);    
    SortTools::testSort("Select Sort",SelectionSort,brr,N);    
    SortTools::testSort("HFInsert Sort",HFInsertSort,crr,N);    
    SortTools::testSort("ImprovedInsert Sort",ImprovedInsertSort,drr,N);    
    SortTools::testSort("mergeSort",mergeSort,err,N);    
    SortTools::testSort("QuickSort",QuickSort,frr,N);    
    delete[] arr;
    delete[] brr;
    delete[] crr;
    delete[] drr;
    delete[] err;
    delete[] frr;

    int swapTimes = 10;
    int *arr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *brr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *crr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *drr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *err2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *frr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    std::cout<<"---------------------"<<std::endl;
    std::cout<<"Nearly ordered Arr: "<< N<<std::endl;
    SortTools::testSort("Bubble Sort",BubbleSort,arr2,N);    
    SortTools::testSort("Select Sort",SelectionSort,brr2,N);    
    SortTools::testSort("HFInsert Sort",HFInsertSort,crr2,N);    
    SortTools::testSort("ImprovedInsert Sort",ImprovedInsertSort,drr2,N);    
    SortTools::testSort("mergeSort",mergeSort,err2,N);    
    SortTools::testSort("QuickSort",QuickSort,frr2,N);    
    delete[] arr2;
    delete[] brr2;
    delete[] crr2;
    delete[] drr2;
    delete[] err2;
    delete[] frr2;

	return 0;
}

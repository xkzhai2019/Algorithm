#include <iostream>
#include "SortTools.h"
#include "BubbleSort.h"
#include "SelectSort.h"

template<typename T>
void InsertSort(T arr[],int n){
    for(int i=1;i<n;i++){
        // 寻找arr[i]合适的插入位置
        /*
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j-1],arr[j]);
            }else{
                break;
            }
        }
        */
        // 写法2
        for(int j=i; j>0 && arr[j]<arr[j-1]; j--){
            swap(arr[j-1],arr[j]);
        }
    }
}

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

int main(void){
    int N = 200000;
    int n = 100;
    int *arr = SortTools::generateNearlyOrderedArr(N,n);
    int *brr = SortTools::generateNearlyOrderedArr(N,n);
    int *crr = SortTools::generateNearlyOrderedArr(N,n);
    int *drr = SortTools::generateNearlyOrderedArr(N,n);

    SortTools::testSort("Bubble Sort",BubbleSort,arr,N);    
    SortTools::testSort("Select Sort",SelectionSort,brr,N);    
    SortTools::testSort("Insert Sort",InsertSort,crr,N);    
    SortTools::testSort("ImprovedInsert Sort",ImprovedInsertSort,drr,N);    

	return 0;
}

#include <iostream>
#include "SortTools.h"
#include "BubbleSort.h"
#include "SelectSort.h"
#include "ImprovedBubbleSort.h"

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
    int N = 20000;
    /* 
    int *arr = SortTools::generateRandomArr(N,0,100000);
    int *brr = SortTools::generateRandomArr(N,0,100000);
    int *crr = SortTools::generateRandomArr(N,0,100000);
    int *drr = SortTools::generateRandomArr(N,0,100000);
    int *err = SortTools::generateRandomArr(N,0,100000);
    */
    
    int *arr = SortTools::generateRandomArr(N,0,3);
    int *brr = SortTools::generateRandomArr(N,0,3);
    int *crr = SortTools::generateRandomArr(N,0,3);
    int *drr = SortTools::generateRandomArr(N,0,3);
    int *err = SortTools::generateRandomArr(N,0,3);
    
    SortTools::testSort("Bubble Sort",BubbleSort,arr,N);    
    SortTools::testSort("Select Sort",SelectionSort,brr,N);    
    SortTools::testSort("Insert Sort",InsertSort,crr,N);    
    SortTools::testSort("ImprovedInsert Sort",ImprovedInsertSort,drr,N);    
    SortTools::testSort("ImprovedBubble Sort",ImprovedBubbleSort,err,N);    

	return 0;
}

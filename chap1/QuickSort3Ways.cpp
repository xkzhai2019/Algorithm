#include <iostream>
#include "SortTools.h"
#include "BubbleSort.h"
#include "SelectSort.h"
#include "HFInsertSort.h"
#include "ImprovedInsertSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort2Ways.h"

// 对arr[l,...,r]进行3路快速排序
template<typename T>
void __QuickSort3(T arr[], int l, int r){
    if(r-l<=15){
        ImprovedInsertSort(arr,l,r);
        return;
    }
    // 随机选取基准元素
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    
    // 分割得到lt,gt
    // 使得arr[l,...,lt-1] <v;  arr[lt,...,gt-1] == v; arr[gt,...,r]> v
    int lt = l;
    int gt = r+1;
    int i = l+1;
    while(i<gt){
        if(arr[i] < v){
            swap(arr[i],arr[lt+1]);
            lt++;
            i++;
        }else if(arr[i] > v){
            swap(arr[i],arr[gt-1]);
            gt--;
        }else{
            i++;
        }
    }
    swap(arr[l],arr[lt]);
    __QuickSort3(arr,l,lt-1);
    __QuickSort3(arr,gt,r);
}

template<typename T>
void QuickSort3Ways(T arr[], int n){
    srand(time(NULL));
    __QuickSort3(arr,0,n-1);
}

int main(void){
    int N = 50000;
    int *arr = SortTools::generateRandomArr(N,0,100000);
    int *brr = SortTools::generateRandomArr(N,0,100000);
    int *crr = SortTools::generateRandomArr(N,0,100000);
    int *drr = SortTools::generateRandomArr(N,0,100000);
    int *err = SortTools::generateRandomArr(N,0,100000);
    int *frr = SortTools::generateRandomArr(N,0,100000);
    int *grr = SortTools::generateRandomArr(N,0,100000);
    int *hrr = SortTools::generateRandomArr(N,0,100000);

    std::cout<<"RandomArr: "<< N<<std::endl;
    SortTools::testSort("Bubble Sort",BubbleSort,arr,N);    
    SortTools::testSort("Select Sort",SelectionSort,brr,N);    
    SortTools::testSort("HFInsert Sort",HFInsertSort,crr,N);    
    SortTools::testSort("ImprovedInsert Sort",ImprovedInsertSort,drr,N);    
    SortTools::testSort("mergeSort",mergeSort,err,N);    
    SortTools::testSort("QuickSort",QuickSort,frr,N);    
    SortTools::testSort("QuickSort2way",QuickSort2Ways,grr,N);    
    SortTools::testSort("QuickSort3way",QuickSort3Ways,hrr,N);    
    delete[] arr;
    delete[] brr;
    delete[] crr;
    delete[] drr;
    delete[] err;
    delete[] frr;
    delete[] grr;
    delete[] hrr;

    int swapTimes = 10;
    int *arr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *brr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *crr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *drr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *err2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *frr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *grr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *hrr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    std::cout<<"---------------------"<<std::endl;
    std::cout<<"Nearly ordered Arr: "<< N<<std::endl;
    SortTools::testSort("Bubble Sort",BubbleSort,arr2,N);    
    SortTools::testSort("Select Sort",SelectionSort,brr2,N);    
    SortTools::testSort("HFInsert Sort",HFInsertSort,crr2,N);    
    SortTools::testSort("ImprovedInsert Sort",ImprovedInsertSort,drr2,N);    
    SortTools::testSort("mergeSort",mergeSort,err2,N);    
    SortTools::testSort("QuickSort",QuickSort,frr2,N);    
    SortTools::testSort("QuickSort2ways",QuickSort2Ways,grr2,N);    
    SortTools::testSort("QuickSort3ways",QuickSort3Ways,hrr2,N);    
    delete[] arr2;
    delete[] brr2;
    delete[] crr2;
    delete[] drr2;
    delete[] err2;
    delete[] frr2;
    delete[] grr2;
    delete[] hrr2;
    
    int *arr3 = SortTools::generateRandomArr(N,0,10);
    int *brr3 = SortTools::generateRandomArr(N,0,10);
    int *crr3 = SortTools::generateRandomArr(N,0,10);
    int *drr3 = SortTools::generateRandomArr(N,0,10);
    int *err3 = SortTools::generateRandomArr(N,0,10);
    int *frr3 = SortTools::generateRandomArr(N,0,10);
    int *grr3 = SortTools::generateRandomArr(N,0,10);
    int *hrr3 = SortTools::generateRandomArr(N,0,10);

    std::cout<<"---------------------"<<std::endl;
    std::cout<<"RandomArr with range(0,10): "<< N<<std::endl;
    SortTools::testSort("Bubble Sort",BubbleSort,arr3,N);    
    SortTools::testSort("Select Sort",SelectionSort,brr3,N);    
    SortTools::testSort("HFInsert Sort",HFInsertSort,crr3,N);    
    SortTools::testSort("ImprovedInsert Sort",ImprovedInsertSort,drr3,N);    
    SortTools::testSort("mergeSort",mergeSort,err3,N);    
    SortTools::testSort("QuickSort",QuickSort,frr3,N);    
    SortTools::testSort("QuickSort2way",QuickSort2Ways,grr3,N);    
    SortTools::testSort("QuickSort3way",QuickSort3Ways,hrr3,N);    
    delete[] arr3;
    delete[] brr3;
    delete[] crr3;
    delete[] drr3;
    delete[] err3;
    delete[] frr3;
    delete[] grr3;
    delete[] hrr3;

	return 0;
}

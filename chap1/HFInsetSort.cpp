#include <iostream>
#include "SortTools.h"
#include "BubbleSort.h"
#include "SelectSort.h"

template<typename T>
void HFInsertSort(T arr[],int n){
    int left=0,right=0;
    int mid;
    for(int i=1;i<n;i++){
        T tmp = arr[i];
        // 利用二分法寻找arr[i]合适的插入位置
        left = 0;
        right = i-1;
        while(left<=right){
            mid = (left + right)/2;
            if(arr[mid] > tmp){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        for(int j=i;j>left;j--){
            arr[j] = arr[j-1];
        }
        arr[left]=tmp;
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
    int N = 50000;
    int *arr = SortTools::generateRandomArr(N,0,100000);
    int *brr = SortTools::generateRandomArr(N,0,100000);
    int *crr = SortTools::generateRandomArr(N,0,100000);
    int *drr = SortTools::generateRandomArr(N,0,100000);
    
    SortTools::testSort("Bubble Sort",BubbleSort,arr,N);    
    SortTools::testSort("Select Sort",SelectionSort,brr,N);    
    SortTools::testSort("HFInsert Sort",HFInsertSort,crr,N);    
    SortTools::testSort("ImprovedInsert Sort",ImprovedInsertSort,drr,N);    

	return 0;
}

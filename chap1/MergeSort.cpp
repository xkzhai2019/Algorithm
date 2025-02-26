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

int main(void){
    int N = 50000;
    int *arr = SortTools::generateRandomArr(N,0,100000);
    int *brr = SortTools::generateRandomArr(N,0,100000);
    int *crr = SortTools::generateRandomArr(N,0,100000);
    int *drr = SortTools::generateRandomArr(N,0,100000);
    int *err = SortTools::generateRandomArr(N,0,100000);

    std::cout<<"RandomArr: "<< N<<std::endl;
    SortTools::testSort("Bubble Sort",BubbleSort,arr,N);    
    SortTools::testSort("Select Sort",SelectionSort,brr,N);    
    SortTools::testSort("HFInsert Sort",HFInsertSort,crr,N);    
    SortTools::testSort("ImprovedInsert Sort",ImprovedInsertSort,drr,N);    
    SortTools::testSort("mergeSort",mergeSort,err,N);    
    delete[] arr;
    delete[] brr;
    delete[] crr;
    delete[] drr;
    delete[] err;

    int swapTimes = 10;
    int *arr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *brr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *crr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *drr2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int *err2 = SortTools::generateNearlyOrderedArr(N,swapTimes);
    std::cout<<"Nearly ordered Arr: "<< N<<std::endl;
    SortTools::testSort("Bubble Sort",BubbleSort,arr2,N);    
    SortTools::testSort("Select Sort",SelectionSort,brr2,N);    
    SortTools::testSort("HFInsert Sort",HFInsertSort,crr2,N);    
    SortTools::testSort("ImprovedInsert Sort",ImprovedInsertSort,drr2,N);    
    SortTools::testSort("mergeSort",mergeSort,err2,N);    
    delete[] arr2;
    delete[] brr2;
    delete[] crr2;
    delete[] drr2;
    delete[] err2;

	return 0;
}

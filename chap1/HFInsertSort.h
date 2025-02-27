#include <iostream>

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


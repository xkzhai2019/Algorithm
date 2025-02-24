#include <iostream>

template<typename T>
void SelectionSort(T arr[],int n){
    for(int i=0;i<n-1;i++){
        // 寻找[i,n)中的最小值
        int minIndex = i;
        for(int j=i+1; j<=n-1;j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        std::swap(arr[i],arr[minIndex]);
    }
}

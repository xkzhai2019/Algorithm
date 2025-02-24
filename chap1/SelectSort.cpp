#include <iostream>
#include "SortTools.h"

void SelectionSort(int arr[],int n){
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

int main(void){
    int a[] = {8,6,3,2,1,7,5,4};
    int length = sizeof(a) / sizeof(a[0]);

    std::cout<<"排序前：";
    SortTools::printArr(a,length);
    SelectionSort(a,length);
    std::cout<<"排序后：";
    SortTools::printArr(a,length);
	return 0;
}

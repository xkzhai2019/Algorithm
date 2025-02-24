#include <iostream>
#include "SortTools.h"

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

int main(void){
    float a[] = {8.1,6.2,2.3,4.5};
    int length = sizeof(a) / sizeof(a[0]);

    std::cout<<"排序前：";
    SortTools::printArr(a,length);
    InsertSort(a,length);
    std::cout<<"排序后：";
    SortTools::printArr(a,length);

	return 0;
}

#include <iostream>
#include "SortTools.h"
#include "Student.h"

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

int main(void){
    float a[] = {8.1,6.2,2.3,4.5};
    int length = sizeof(a) / sizeof(a[0]);

    Student sd[4] = {{"D",90},{"C",100},{"B",95},{"A",90}};
    

    std::cout<<"排序前：";
    SortTools::printArr(a,length);
    SelectionSort(a,length);
    std::cout<<"排序后：";
    SortTools::printArr(a,length);

    std::cout<<"排序前：";
    SortTools::printArr(sd,4);
    SelectionSort(sd,sizeof(sd) / sizeof(sd[0]));
    std::cout<<"排序后：";
    SortTools::printArr(sd,4);

    //测试随机数排序
    int N = 40000;
    int *arr = SortTools::generateRandomArr(N,0,100000);
    std::cout<<"排序前：";
    SortTools::printArr(arr,20);
    SelectionSort(arr,N);
    std::cout<<"排序后：";
    SortTools::printArr(arr,20);

    int *brr = SortTools::generateRandomArr(N,0,100000);
    SortTools::testSort("Select Sort",SelectionSort,brr,N);    
	return 0;
}

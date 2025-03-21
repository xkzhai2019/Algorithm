#include <iostream>
using namespace std;

template<typename T>
void BubbleSort(T arr[], int length){
    for(int i=1;i<=length-1;i++){// 总共进行length-1轮排序
        for(int j=1;j<=length-i;j++){// 第i轮排序需比较length- i次
            // 每次用arr[j-1] 与 arr[j]比较
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int length){
    for(int i=1;i<=length-1;i++){// 总共进行length-1轮排序
        for(int j=1;j<=length-i;j++){// 第i轮排序需比较length- i次
            // 每次用arr[j-1] 与 arr[j]比较
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}

void printArr(int arr[], int length){
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

int main(void){
    int a[] = {8,6,3,2,1,7,5,4};
    //int length = 8;
    int length = sizeof(a) / sizeof(a[0]);

    cout<<"排序前：";
    printArr(a,length);
    bubbleSort(a,length);
    cout<<"排序后：";
    printArr(a,length);
	return 0;
}

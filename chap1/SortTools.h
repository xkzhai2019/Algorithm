#include <iostream>
#include <cassert>
using namespace std;

namespace SortTools{

    // 生成n个元素的随机数组，随机范围[rangeL,rangeR]
    int *generateRandomArr(int n, int rangeL, int rangeR){
        assert(rangeL<=rangeR);
        int *arr = new int[n];

        // 随机种子
        srand(0);
        //srand(time(NULL));
        for(int i=0;i<n;i++){
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    // 生成近乎有序的随机数组
    int *generateNearlyOrderedArr(int n, int swapTimes){
        int *arr = new int[n];
        for(int i=0;i<n;i++)
            arr[i] = i;

        srand(0);
        for(int i=0;i<swapTimes;i++){
            int posx = rand()%n;
            int posy = rand()%n;
            swap(arr[posx],arr[posy]);
        }
        return arr;
    }

    // 打印数组内容 
    template<typename T>
    void printArr(T arr[], int length){
        for(int i=0;i<length;i++){
            std::cout<<arr[i]<<" ";
        }
        std::cout<<std::endl;
    }

    template<typename T>
    bool isSorted(T arr[],int n){
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1])
                return false;
        }
        return true;
    }
    // 测试算法运行时间
    template<typename T>
    void testSort(const string& sortName,void (*sort)(T[],int),T arr[],int n){
       clock_t startTime = clock();
       sort(arr,n);
       clock_t endTime = clock();

       assert(isSorted(arr,n));
       cout<<sortName<<": "<< double(endTime - startTime) / CLOCKS_PER_SEC << "s"<<endl;
    }
}

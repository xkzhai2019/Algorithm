#include <iostream>
#include "QuickSort2Ways.h"
using namespace std;

template<typename T>
bool HalfFind(T a[],int length, T tmp){
    int l = 0, r = length-1;
    while(l<=r){
        int mid = (l+r) / 2;
        if(a[mid]==tmp){
            return true;
        }else if(a[mid]<tmp){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return false;
}

//基于排序的优化

int main(){
    int n = 3;
    int m = 10;
    int a[] = {1,3,5};
    int length = sizeof(a) / sizeof(a[0]);

    QuickSort2Ways(a,length);// o(nlogn)
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                int tmp = m - a[i] - a[j] - a[k];
                if(HalfFind(a,length,tmp)){
                    std::cout<<"Yes"<<std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout<<"No"<<std::endl;
    return 0;
}

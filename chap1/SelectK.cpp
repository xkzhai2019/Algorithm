#include <iostream>
#include "SortTools.h"

// 对arr[l,...,r]进行分割，分割为三部分
// 返回j，使得arr[l,...,j-1] < arr[j];  arr[j+1,...,r]> arr[j]
template<typename T>
int __partition(T arr[],int l,int r){
    // 基准元素
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    int j = l; // arr[l+1,...,j]< v; arr[j+1,...,i-1]>v
    for(int i=l+1;i<=r;i++){
        if(arr[i]<v){
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    swap(arr[l],arr[j]);
    return j;
}


// 求出arr[l,...,r]范围内第k小的数
template<typename T>
T __SelectK(T arr[], int l, int r, int k){
    if(l==r)
        return arr[l];
    int j = __partition(arr,l,r);//分割后的j，就是排名
    if(j==k){
        return arr[j];
    }else if(j>k){// 如果k<j,则在arr[l,...,j-1]中找第k小元素
        return __SelectK(arr,l,j-1,k);
    }else{// 如果k > j，则在arr[j+1,...,r]中找第k小元素
        return __SelectK(arr,j+1,r,k);
    }
}

template<typename T>
T SelectK(T arr[], int n, int k){// 寻找arr中第k小的元素
    assert(k>=0 && k<n);
    srand(time(NULL));
    return __SelectK(arr,0,n-1,k);// 寻找arr[0,...,n-1]中第k小的元素
}

int main(void){
    int N = 50000;
    int swapTimes = 10;
    int *arr = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int brr[] = {1,4,3,2,6,7,8,9,5};
    std::cout<<SelectK(arr,N,10)<<std::endl;
    std::cout<<SelectK(brr,9,5)<<std::endl;
	return 0;
}

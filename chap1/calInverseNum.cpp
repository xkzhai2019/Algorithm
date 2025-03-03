#include <iostream>
#include "SortTools.h"
// 使用归并排序思想计算无序数组中的逆序对

template<typename T>
int mergeCal(T arr[], int l, int mid, int r){
    //求出arr[l,...,mid]和arr[mid+1,...,r]有序的基础上，arr[l,...,r]的逆序对个数
    // 复制一份arr
    T *brr = new T[r-l+1];
    for(int i=0;i<r-l+1;i++){
        brr[i] = arr[i+l];
    }
    
    int res = 0;
    int i = l;// i指向左半部分起始索引位置
    int j = mid+1; //j指向右半部分起始位置

    for(int k=l;k<=r;k++){
        if(i>mid){// 左半部分已经遍历结束
            arr[k] = brr[j-l];
            j++;
        }else if(j>r){// 右半部分已经遍历结束
            arr[k] = brr[i-l];
            i++;
        }else if(brr[i-l] <= brr[j-l]){//左半部分所指元素 < 右半部分所指元素
            arr[k] = brr[i-l];
            i++;
        }else{// 左半部分所指元素 > 右半部分所指元素
            arr[k] = brr[j-l];
            j++;
            res += mid - i + 1;
        }
    }
    delete[] brr;
    return res;
}

// 求arr[l,...,r]中逆序对的个数
template<typename T>
int calInverseNum(T arr[], int l, int r){
    // 边界情况：l == r
    if(l>=r){
        return 0;
    }
    
    int mid = (l+r)/2;
    //求出arr[l,...,mid]范围的逆序对个数
    int res1 = calInverseNum(arr,l,mid);
    //求出arr[mid+1,...,r]范围的逆序对个数
    int res2 = calInverseNum(arr,mid+1,r);
    
    return res1 + res2 + mergeCal(arr,l,mid,r);
}

template<typename T>
int calInverseNum(T arr[],int n){// 递归求arr[0,...,n-1]范围的逆序对个数
    return calInverseNum(arr,0,n-1);
}

int main(void){
    int N = 50000;
    int swapTimes = 0;
    int *arr = SortTools::generateNearlyOrderedArr(N,swapTimes);
    int brr[] = {1,3,4,5,2,6,7,8};
    std::cout<<calInverseNum(arr,N)<<std::endl;
    std::cout<<calInverseNum(brr,8)<<std::endl;
	return 0;
}

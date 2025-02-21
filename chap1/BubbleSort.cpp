#include <iostream>
using namespace std;
// 冒泡排序：从小到大
int main(void){
    int a[] = {8,6,3,2,1,7,5,4};
    //int length = 8;
    int length = sizeof(a) / sizeof(a[0]);
    int tmp;
    // 打印排序前的数组
    cout<<"排序前：";
    for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=length-1;i++){// 总共进行length-1轮排序
        for(int j=1;j<=length-i;j++){// 第i轮排序需比较length- i次
            // 每次用a[j-1] 与 a[j]比较
            if(a[j]<a[j-1]){
                tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
            }
        }
    }
    // 打印排序后的数组
    cout<<"排序后：";
    for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

#include <iostream>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int a[n+1] = {0};
    int count[4] = {0};
    for(int i=1;i<=n;i++){
        cin >> a[i];
        count[a[i]]++; //count[1]、count[2]、count[3]
        // 1：1～count[1];
        // 2: count[1]+1 ~ count[1] + count[2]
        // 3: count[1] + count[2] + 1 ~ count[1] + count[2] + count[3]
    }
    int res = 0; // 记录交换次数
    int j = count[1]+1; // 2区间的起始位置
    int k = count[1]+count[2]+1; //3区间的起始位置
    for(int i=1;i<=count[1];i++){ // 先对1区间排序
        if(a[i]==2){//1区间的某个位置是2
            // 将它与2区间某个1交换
            while(j<=count[1]+count[2] && a[j]!=1){
                j++; 
            }
            if(j<=count[1]+count[2]){ // 如果找到这样的1，则交换
                swap(a[i],a[j]);
                res++;
            }// 若2区间找不到1，则a[i]不动
        }else if(a[i]==3){// 1区间某个位置是3
            // 将它与3区间某个1交换
            while(k<=count[1]+count[2]+count[3] && a[k]!=1){
                k++;
            }
            if(k<=n){//如果找到这样的1，则交换
                swap(a[i],a[k]);
                res++;
            }
        }
    }

    // 11123 223 131
    // 11121 223 331
    // 经过上面一轮交换：1区间内存在2，3区间内存在1；|| 1区间内存在3，2区间内存在1
    // 只需把剩余的1交换到正确的位置，2和3错位则留到最后
    j = count[1] + 1;
    for(int i=1;i<=count[1];i++){
        if(a[i]!=1){
            while(j<=n && a[j]!=1){
                j++;
            }
            if(j<=n){
                swap(a[i],a[j]);
                res++;
            }
        }
    }

    // 经过上一轮交换，1区间内就全部都是1了，2区间内的3和3区间内的2，数目是完全对应的
    for(int i=count[1]+1; i<=count[1]+count[2];i++){
        if(a[i]==3){
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}

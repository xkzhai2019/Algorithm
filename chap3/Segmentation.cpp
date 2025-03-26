#include <iostream>
using namespace std;

int n, k;
int a[100];
// 使用贪心法计算最少分段数
int segmentation(int T){
    int res = 0;
    int prosum = 0;
    for(int i=0;i<n;i++){
        if(a[i]>T){
            return n+100;
        }
        if(prosum + a[i] <= T){
            prosum += a[i];
        }else{
            prosum = a[i];
            res++;
        }
    }
    return res+1;
}

int main(){
    cin>>n>>k;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    // 二分答案
    int l = sum / k;
    int r = sum;
    while(l<r){
        int mid = (l+r)/2;
        if(segmentation(mid)<=k){
            r = mid;
        }else{
            l = mid + 1;
        }
    }

    cout << l << endl;
    cout << r << endl;
    return 0;
}


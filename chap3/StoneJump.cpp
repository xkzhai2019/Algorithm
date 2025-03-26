#include <iostream>
using namespace std;
int l,n,m;
int d[100];

// 最短距离为gap时需要移走的最少石头数
// 只要当前石头和上一个石头之间的距离< gap就移走
int removeAndCount(int gap){
    int count=0, prev = 0;
    for(int i=0;i<n;i++){
        if(d[i] - prev < gap){
            count++;
        }else{
            prev = d[i];
        }
    }
    if(l-d[n-1]<gap){
        count++;
    }
    return count;
}

int main(){
    cin>>l>>n>>m;
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    int l = 1;
    int r = l;
    int mid;
    while(l<r){
        mid = (l+r)/2;
        if(removeAndCount(mid)<=m){
            l = mid + 1;            
        }else{
            r = mid;
        }
    }
    if(removeAndCount(l)>m){
        l--;
    }
    cout<<l<<endl;

    return 0;
}

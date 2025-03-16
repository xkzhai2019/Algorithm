#include <iostream>
#include <algorithm>
using namespace std;
struct goods{
    int price;
    int num;
}a[10];

bool cmp(goods A, goods B){
    return A.price < B.price;
}

int main(){
    int m,n;
    int ans = 0;
    cin>>m>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].price>>a[i].num;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        if(m>a[i].price*a[i].num){
            ans += a[i].num;
            m -= a[i].price*a[i].num;
        }else{
            int tmNum = m/ a[i].price;
            ans += tmNum;
            m -= a[i].price*tmNum;
        }
    }
    cout<<ans<<endl;
    return 0;
}

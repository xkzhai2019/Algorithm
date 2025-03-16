#include <iostream>
#include <algorithm>
using namespace std;

// 待支付的总费用total
// n种面值的钱币，每种纸币无限张
// 要求使用最少的钱币张数支付total
// 输入样例：
// 58 4
// 1 10 5 20
// 输出
// 7

int main(){
    int total, n;
    int num = 0;
    int money[100];
    cin >> total >> n;
    for(int i=0;i<n;i++){
        cin>>money[i];
    }
    sort(money,money+n,greater<int>());
    for(int i=0;i<n;i++){
        int tmp = total/money[i];
        if(tmp>0){
            total -= tmp*money[i];
            num += tmp;
        }
    }
    cout<<num;
    return 0;
}

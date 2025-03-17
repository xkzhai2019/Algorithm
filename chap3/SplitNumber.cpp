#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n==3){
        cout << 1 << ' ' << 2 <<endl;
        cout << 2 << endl;
        return 0;
    }
    if(n==4){
        cout << 1 << ' ' << 3 <<endl;
        cout << 3 <<endl;
        return 0;
    }
    int res[n],k=0;
    memset(res,0,sizeof(res));
    for(int i = 2; i < 10000; i++){
        // 如果剩余的数字>i,那么i就可以作为一个分解出来的数字
        if(n>=i){
            res[k++] = i;
            n -= i;
        }else{
            // n现在为余数
            // 按从大到小的顺序给每个数字+1
            while(n>0){
                for(int j=k-1; j>=max(0,k-n); j--){
                    res[j]++;
                }
                n -= k;
            }
            break;
        }
    }
    // 输出划分方案
    cout<<res[0];
    for(int i=1;i<k;i++){
        cout<<' '<<res[i];
    }
    cout<<endl;
    // 输出乘积
    int product = 1;
    for(int i=0;i<k;i++){
        product *= res[i];
    }
    cout<<product<<endl;

    return 0;
}

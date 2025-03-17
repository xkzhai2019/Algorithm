#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N,S;
    cin>>N>>S; // 总周数，每周保养费用
    int C,Y; //每周生产成本，交付台数
    int total = 0; // 总花费
    int min_p = 1000000; // 前k周最低成本
    for(int i=0;i<N;i++){
        cin>>C>>Y;// 第i周生产成本，交付台数
        min_p = min(min_p+S,C);// 更新当前最小成本
        total += min_p*Y; // 计算当前星期的总花费
    }
    cout<<total<<endl;
    return 0;
}

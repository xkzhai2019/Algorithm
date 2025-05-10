#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 用[0,...,index]的物品，填充容积为C的背包的最大价值
int bestValue(const vector<int> &w,const vector<int> &v, int index, int C){
    if(C<=0 || index<0){
        return 0;
    }
    int res = bestValue(w,v,index-1,C);
    if(C>=w[index]){
        res = max(res,v[index]+bestValue(w,v,index-1,C-w[index]));
    }
    return res;
}
int knapsack01(const vector<int> &w, const vector<int> &v, int C){
    assert(w.size()==v.size() && C>=0);
    int n = w.size();
    if(n==0 || C==0){
        return 0;
    }
    return bestValue(w,v,n-1,C);
}

int main(){
    int n,W;
    cin>>n>>W;
    int v,w;
    vector<int> vs,ws;
    for(int i=0;i<n;i++){
        cin>>w>>v;
        vs.push_back(v);
        ws.push_back(w);
    }
    cout<<knapsack01(ws,vs,W)<<endl;   
    return 0;
}

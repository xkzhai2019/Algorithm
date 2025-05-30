#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 动态规划
int knapsack01(const vector<int> &w, const vector<int> &v, int C){
    assert(w.size()==v.size() && C>=0);
    int n = w.size();
    if(n==0 || C==0){
        return 0;
    }
    vector<vector<int>> memo(n,vector<int>(C+1,0));
    for(int j=0;j<=C;j++)
        memo[0][j] = (j>=w[0] ? v[0]:0);

    for(int i=1;i<n;i++){
        for(int j=0;j<=C;j++){
            memo[i][j] = memo[i-1][j];
            if(j>=w[i])
                memo[i][j] = max(memo[i][j],v[i]+memo[i-1][j-w[i]]);
        }
    }
    return memo[n-1][C];
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

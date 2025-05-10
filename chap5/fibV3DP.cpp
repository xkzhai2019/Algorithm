#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

vector<int> memo;

// 动态规划计算斐波那契数列
int fib(int n){
    memo = vector<int>(n+1,-1);
    memo[0] = 0;
    memo[1] = 1;
    for(int i=2;i<=n;i++){
        memo[i] = memo[i-1] + memo[i-2];
    }
    return memo[n];
}

int main(){
    int n;
    cin>>n;
    time_t startTime = clock();
    int res = fib(n);
    time_t endTime = clock();
    cout<<"fib("<<n<<")="<<res<<endl;
    cout<<"time:"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}

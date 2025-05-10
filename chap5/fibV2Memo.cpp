#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// int memo[100];
vector<int> memo;
int number;

// 记忆化搜索计算斐波那契数列
int fib(int n){
    number++;
    assert(n>=1);
    if(n==1 || n==2){
        return 1;
    }
    if(memo[n]==-1){
        memo[n] = fib(n-1) + fib(n-2);
    }
    return memo[n];
}

int main(){
    int n;
    cin>>n;
    memo = vector<int>(n+1,-1);
    time_t startTime = clock();
    int res = fib(n);
    time_t endTime = clock();
    cout<<"fib("<<n<<")="<<res<<endl;
    cout<<"time:"<<double(endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
    cout<<"call fib(): "<<number<<"times."<<endl;
    return 0;
}

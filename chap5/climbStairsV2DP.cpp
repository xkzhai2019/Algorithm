#include <iostream>
#include <vector>
using namespace std;

// 动态规划
vector<int> memo;
class Solution{
private:
    int calWays(int n){
        memo[0]=1;
        memo[1]=1;
        for(int i=2;i<=n;i++){
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }
public:
    int climbStairs(int n) {
        memo = vector<int>(n+1,-1);
        return calWays(n);
    }
};
int main(){
    cout<<Solution().climbStairs(3)<<endl;
    return 0;
}

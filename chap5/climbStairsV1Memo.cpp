#include <iostream>
#include <vector>
using namespace std;

// 记忆化搜索
vector<int> memo;
class Solution{
private:
    int calWays(int n){
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(memo[n] == -1){
            memo[n] = calWays(n-1) + calWays(n-2);
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

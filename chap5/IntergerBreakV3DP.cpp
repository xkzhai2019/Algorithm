#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
// 动态规划
class Solution {
private:
    vector<int> memo;
    int max3(int a,int b,int c){
        return max(a,max(b,c));
    }
public:
    int integerBreak(int n) {
        assert(n>=1);
        vector<int> memo(n+1,-1);
        memo[1] = 1;
        for(int i=2;i<=n;i++){
            // 求解memo[i]
            for(int j=1;j<=i-1;j++){
                memo[i] = max3(memo[i],j*(i-j),j*memo[i-j]);
            }
        }
        return memo[n];
    }
};

int main(){
    cout<<Solution().integerBreak(2)<<endl;
    cout<<Solution().integerBreak(10)<<endl;
    return 0;
}

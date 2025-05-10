#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n,-1);
        memo[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            // 求memo[i]: 抢劫nums[i,...,n-1]能获得的最大收益
            for(int j=i;j<n;j++){
                memo[i] = max(memo[i],nums[j]+(j+2<n?memo[j+2]:0));
            }
        }
        return memo[0];
    }
};

int main(){
    int nums[] = {2,3,1,4};
    vector<int> vec(nums,nums+sizeof(nums)/sizeof(int));

    cout<<Solution().rob(vec)<<endl;
    return 0;
}

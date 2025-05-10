#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> memo;
   int tryRob(const vector<int> &nums,int index){
       if(index>=nums.size()){
           return 0;
       }
       if(memo[index]!=-1){
           return memo[index];
       }
       int res = 0;
       for(int i=index; i<nums.size(); i++){//按层遍历
           res = max(res,nums[i]+tryRob(nums,i+2));
       }
       memo[index] = res;
       return res;
   }

public:
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(),-1);
        return tryRob(nums,0);
    }
};

int main(){
    int nums[] = {2,3,1,4};
    vector<int> vec(nums,nums+sizeof(nums)/sizeof(int));

    cout<<Solution().rob(vec)<<endl;
    return 0;
}

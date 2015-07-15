class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int i = 0 ;i < nums.size(); i ++){
            if(i == 0)
                dp[i] = nums[i];
            else
                dp[i] = max(dp[i-1] + nums[i], nums[i]);
        }
        return *max_element(begin(dp),end(dp));
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size() ; i ++){
            if( nums[i] == val)
                cnt ++;
            else{
                if(cnt > 1)
                    cnt --;
                else{
                    val = nums[i];
                }
            }
        }
        return val;
    }
};

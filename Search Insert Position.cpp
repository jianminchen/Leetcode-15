class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid, res = nums.size();
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == target){
                res = mid;
                break;
            }
            if(target < nums[mid]){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }
};

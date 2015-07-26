class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return min(nums[0], nums[1]);
        int low = 0, high = nums.size() - 1, mid;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid + 1] > nums[mid] && nums[mid - 1] > nums[mid]) return nums[mid];
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return nums[mid];
    }
};

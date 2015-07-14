class Solution {
public:
	void RadixSort(vector<int>& nums, long long mod) {
		vector< vector<int> > bins(10);
		bool end = true;
		for (int i = 0; i < nums.size(); i++) {
			bins[nums[i] / mod % 10].push_back(nums[i]);
			if (nums[i] / mod > 0)
				end = false;
		}
		nums.clear();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < bins[i].size(); j++) {
				nums.push_back(bins[i][j]);
			}
		}
		if (end == false)
			RadixSort(nums, mod * 10);
	}
	int longestConsecutive(vector<int>& nums) {
		if(nums.size() == 0) return 0;
		
		vector<int> neg, pos;
		copy_if(nums.begin(), nums.end(), back_inserter(neg), [](int v) {return v < 0; });
		copy_if(nums.begin(), nums.end(), back_inserter(pos), [](int v) {return v >= 0; });

		transform(neg.begin(), neg.end(), neg.begin(), [](int v) {return -(v + 1); });
		RadixSort(neg, 1);
		reverse(neg.begin(), neg.end());
		transform(neg.begin(), neg.end(), neg.begin(), [](int v) {return -(v + 1); });

		RadixSort(pos, 1);
		
		nums = neg;
		copy(pos.begin(), pos.end(), back_inserter(nums));
		nums.erase(unique(nums.begin(),nums.end()), nums.end());
		
		int maxLen = 1, len = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1] + 1) {
				len++;
				maxLen = max(maxLen, len);
			}
			else {
				len = 1;
			}
		}
		return maxLen;
	}
};

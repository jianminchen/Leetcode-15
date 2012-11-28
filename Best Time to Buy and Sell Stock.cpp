class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = 0, cur = 0;
        vector<int> mx(prices.size(),0);
        for(int i = prices.size() - 1 ; i > 0 ; i --)
        {
            cur = max(cur, prices[i]);
            mx[i] = cur;
        }
        for(int i = 0 ;i < (int)prices.size() - 1 ;i ++)
        {
            ans = max(ans,mx[i+1] - prices[i]);
        }
        return ans;
    }
};
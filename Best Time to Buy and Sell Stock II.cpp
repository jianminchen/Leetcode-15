class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        if(n == 0) return 0;
        vector< pair<int,int> > dp(n + 1 , make_pair(0,0));
        dp[1].second = -prices[0];
        for(int i = 2 ; i <= n ; i ++ )
        {
            dp[i].first = max(dp[i-1].first, dp[i-1].second + prices[i-1]);
            dp[i].second = max(dp[i-1].second, dp[i-1].first - prices[i-1]);
        }
        return dp[n].first;
    }
};
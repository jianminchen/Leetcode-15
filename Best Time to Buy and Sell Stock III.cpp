class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        if(n == 0) return 0;
        int dp[n+1][2][3];
        memset(dp,0,sizeof(dp));
        
        dp[1][1][0] = - prices[0];
        dp[1][1][1] = dp[1][1][2] = -1000000000;
        
        for(int i = 2 ; i<= n ; i++ )
        {
            dp[i][0][0] = dp[i-1][0][0];
            dp[i][0][1] = max(dp[i-1][0][1],dp[i-1][1][0] + prices[i-1]);
            dp[i][0][2] = max(dp[i-1][0][2],dp[i-1][1][1] + prices[i-1]);
            
            dp[i][1][0] = max(dp[i-1][1][0],dp[i-1][0][0] - prices[i-1]);
            dp[i][1][1] = max(dp[i-1][1][1],dp[i-1][0][1] - prices[i-1]);
            dp[i][1][2] = max(dp[i-1][1][2],dp[i-1][0][2] - prices[i-1]);
        }
        return max(dp[n][0][0],max(dp[n][0][1], dp[n][0][2]));
        
    }
};
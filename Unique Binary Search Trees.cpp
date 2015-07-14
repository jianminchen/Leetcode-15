class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n ; i ++){
            for(int j = 0 ; j <= i-1; j ++){
                int k = (i-1) - j;
                dp[i] += dp[j] * dp[k];
            }
        }
        return dp[n];
    }
};

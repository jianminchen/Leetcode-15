class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int n = triangle.size();
		vector<vector<int> > dp = vector<vector<int> >(2, vector<int>(n, 1e10));
		dp[0][0] = triangle[0][0];
		for (int i = 0; i < n - 1; i++)
		{
			dp[(i + 1) % 2] = vector<int>(n, 1e10);
			for (int j = 0; j <= i; j++)
			{
				dp[(i + 1) % 2][j] = min(dp[(i + 1) % 2][j], dp[i % 2][j] + triangle[i + 1][j]);
				dp[(i + 1) % 2][j + 1] = min(dp[(i + 1) % 2][j + 1], dp[i % 2][j] + triangle[i + 1][j + 1]);
			}
		}
		return *min_element(dp[(n - 1) % 2].begin(), dp[(n - 1) % 2].end());
	}
};

class Solution {
public:
	int jump(int A[], int n) {
		vector<int> leftMost(n, -1);
		int rightMost = 0;
		for (int i = 0; i < n; i++)
		{
			if (i + A[i] > rightMost)
			{
				for (int j = rightMost + 1; j <= i + A[i] && j < n; j++)
				{
					leftMost[j] = i;
				}
				rightMost = i + A[i];
			}
		}
		int now = n - 1, ans = 0;
		while (now != 0)
		{
			now = leftMost[now];
			ans++;
		}
		return ans;
	}
};

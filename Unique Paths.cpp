class Solution {
public:
    int uniquePaths(int m, int n) {
        int C[201][201];
        memset(C, 0, sizeof(C));
        C[0][0] = 1;
        for(int i = 1; i <= 200; i ++){
            C[i][0] = C[i-1][0];
            for(int j = 1; j <= i; j ++){
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
        return C[m + n - 2][n - 1];
    }
};

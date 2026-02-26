class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(i + 1, 1e9);
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                if (i == n - 1) {
                    dp[i][j] = triangle[i][j];
                } else {
                    int downLeft = triangle[i][j] + dp[i + 1][j];
                    int downRight = triangle[i][j] + dp[i + 1][j + 1];

                    dp[i][j] = min(downLeft, downRight);
                }
            }
        }
        return dp[0][0];
    }
};
class Solution {
public:
    int minSum(int i, int j, int n, vector<vector<int>>& triangle,
               vector<vector<int>>& dp) {

        if (i == n - 1) {
            return triangle[i][j];
        }

        if (dp[i][j] != 1e9) {
            return dp[i][j];
        }

        int down = triangle[i][j] + minSum(i + 1, j, n, triangle, dp);
        int downRight = triangle[i][j] + minSum(i + 1, j + 1, n, triangle, dp);

        dp[i][j] = min(down, downRight);
        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(i + 1, 1e9);
        }

        return minSum(0, 0, n, triangle, dp);
    }
};
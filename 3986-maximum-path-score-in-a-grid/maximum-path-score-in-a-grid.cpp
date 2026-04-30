class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, int k,
              vector<vector<vector<int>>>& dp) {
        if (i < 0 || j < 0) {
            return INT_MIN;
        }

        int cost = grid[i][j] == 0 ? 0 : 1;
        if (k < cost)
            return INT_MIN;

        if (i == 0 && j == 0) {
            return 0;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        int up = solve(i - 1, j, grid, k - cost, dp);
        int left = solve(i, j - 1, grid, k - cost, dp);

        int bestPath = max(up, left);
        
        if (bestPath == INT_MIN) {
            return dp[i][j][k] = INT_MIN;
        }
        return dp[i][j][k] = bestPath + grid[i][j];
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

        int ans = solve(n - 1, m - 1, grid, k, dp);
        return ans < 0 ? -1 : ans;
    }
};
class Solution {
public:
    const int MOD = 1e9 + 7;
    int rows, cols;

    pair<long long, long long> dfs(int r, int c, vector<vector<int>>& grid,
                                  vector<vector<pair<long long, long long>>>& dp) {
        if (dp[r][c].first != LLONG_MIN) return dp[r][c];

        if (r == 0 && c == 0) {
            return dp[r][c] = {grid[0][0], grid[0][0]};
        }

        long long maxVal = LLONG_MIN, minVal = LLONG_MAX;

        if (r > 0) {
            auto up = dfs(r - 1, c, grid, dp);
            maxVal = max(maxVal, max(up.first * grid[r][c], up.second * grid[r][c]));
            minVal = min(minVal, min(up.first * grid[r][c], up.second * grid[r][c]));
        }

        if (c > 0) {
            auto left = dfs(r, c - 1, grid, dp);
            maxVal = max(maxVal, max(left.first * grid[r][c], left.second * grid[r][c]));
            minVal = min(minVal, min(left.first * grid[r][c], left.second * grid[r][c]));
        }

        return dp[r][c] = {maxVal, minVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        vector<vector<pair<long long, long long>>> dp(
            rows, vector<pair<long long, long long>>(cols, {LLONG_MIN, LLONG_MIN})
        );

        auto result = dfs(rows - 1, cols - 1, grid, dp);

        if (result.first < 0) return -1;
        return result.first % MOD;
    }
};
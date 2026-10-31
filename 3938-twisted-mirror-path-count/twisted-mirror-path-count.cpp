class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;

    vector<vector<int>> dp;

    int resolve(int i, int j, int dir, vector<vector<int>>& grid) {
        while (i < m && j < n) {
           
            if (grid[i][j] == 0) {
                return solve(i, j, grid);
            }

            if (dir == 0) {
                i++;
                dir = 1;
            } else {
                j++;
                dir = 0;
            }
        }

        return 0;
    }

    int solve(int i, int j, vector<vector<int>>& grid) {
        if (i >= m || j >= n) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        long long down = 0;
        long long right = 0;

        if (i + 1 < m) {
            down = resolve(i + 1, j, 1, grid);
        }

        if (j + 1 < n) {
            right = resolve(i, j + 1, 0, grid);
        }

        return dp[i][j] = (down + right) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<int>(n, -1));

        return solve(0, 0, grid);
    }
};
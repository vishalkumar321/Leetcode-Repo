typedef long long ll;
int MOD = 1e9 + 7;

class Solution {
public:
    int solve(int i, int j, int rem, vector<vector<int>>& grid, int k,
              vector<vector<vector<ll>>>& dp) {

        if (i < 0 || j < 0) {
            return 0;
        }

        if (i == 0 && j == 0) {
            return (grid[0][0] % k == rem) ? 1 : 0;
        }

        if (dp[i][j][rem] != -1) {
            return dp[i][j][rem];
        }

        int value = grid[i][j] % k;
        int prevMod = (rem - value + k) % k;

        ll up = solve(i - 1, j, prevMod, grid, k, dp);
        ll left = solve(i, j - 1, prevMod, grid, k, dp);

        dp[i][j][rem] = (up + left) % MOD;
        return dp[i][j][rem];
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<ll>>> dp(m,
                                      vector<vector<ll>>(n, vector<ll>(k, -1)));

        return solve(m - 1, n - 1, 0, grid, k, dp);
    }
};
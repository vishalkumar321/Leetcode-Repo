// SPACE OPTIMIZATION APPROACH
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n,0);

        for (int i = 0; i < m; i++) {
            vector<int>curr(n,0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = grid[0][0];
                } else {
                    int up = 1e9;
                    int left = 1e9;

                    if (i > 0)
                        up = grid[i][j] + prev[j];
                    if (j > 0)
                        left = grid[i][j] + curr[j - 1];

                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};



// BOTTOM-UP APPROACH
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == 0 && j == 0) {
//                     dp[i][j] = grid[0][0];
//                 } else {
//                     int up = 1e9;
//                     int left = 1e9;

//                     if (i > 0)
//                         up = grid[i][j] + dp[i - 1][j];
//                     if (j > 0)
//                         left = grid[i][j] + dp[i][j - 1];

//                     dp[i][j] = min(up, left);
//                 }
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };



// TOP-DOWN APPROACH
// class Solution {
// public:
//     int solve(vector<vector<int>>& grid, int m, int n,
//               vector<vector<int>>& dp) {

//         if (m == 0 && n == 0) {
//             return grid[0][0];
//         }
//         if (m < 0 || n < 0) {
//             return 1e9;
//         }
//         if (dp[m][n] != -1) {
//             return dp[m][n];
//         }

//         int up = grid[m][n] + solve(grid, m - 1, n, dp);
//         int left = grid[m][n] + solve(grid, m, n - 1, dp);

//         dp[m][n] = min(up, left);
//         return dp[m][n];
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return solve(grid, m - 1, n - 1, dp);
//     }
// };
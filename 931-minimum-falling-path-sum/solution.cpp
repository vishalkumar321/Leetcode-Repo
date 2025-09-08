// SPACE OPTIMIZATION APPROACH
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        for (int j = 0; j < n; j++) {
            prev[j] = matrix[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i == n - 1) {
                    curr[j] = matrix[i][j];
                } else {
                    int down = matrix[i][j] + prev[j];
                    int leftDiagonal = j > 0 ? matrix[i][j] + prev[j - 1] : 1e9;
                    int rightDiagonal =
                        j < n - 1 ? matrix[i][j] + prev[j + 1] : 1e9;
                    curr[j] = min(down, min(leftDiagonal, rightDiagonal));
                }
            }
            prev = curr;
        }
        int ans = 1e9;
        for (int j = 0; j < n; j++) {
            ans = min(ans, prev[j]);
        }
        return ans;
    }
};

// BOTTOM-UP APPROACH
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));

//         for (int j = 0; j < n; j++) {
//             dp[n - 1][j] = matrix[n - 1][j];
//         }

//         for (int i = n - 2; i >= 0; i--) {
//             for (int j = 0; j < n; j++) {
//                 if (i == n - 1) {
//                     dp[i][j] = matrix[i][j];
//                 } else {
//                     int down = matrix[i][j] + dp[i + 1][j];
//                     int leftDiagonal =
//                         j > 0 ? matrix[i][j] + dp[i + 1][j - 1] : 1e9;
//                     int rightDiagonal =
//                         j < n - 1 ? matrix[i][j] + dp[i + 1][j + 1] : 1e9;
//                     dp[i][j] = min(down, min(leftDiagonal, rightDiagonal));
//                 }
//             }
//         }
//         int ans = 1e9;
//         for (int j = 0; j < n; j++) {
//             ans = min(ans, dp[0][j]);
//         }
//         return ans;
//     }
// };

// TOP-DOWN APPROACH
// class Solution {
// public:
//     int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>&
//     dp) {
//         int n = matrix.size();

//         if (j < 0 || j >= n)
//             return 1e9;
//         if (i == n - 1)
//             return matrix[n - 1][j];

//         int down = matrix[i][j] + solve(matrix, i + 1, j, dp);
//         int diagonalLeft = matrix[i][j] + solve(matrix, i + 1, j - 1, dp);
//         int diagonalRight = matrix[i][j] + solve(matrix, i + 1, j + 1, dp);

//         dp[i][j] = min(down, min(diagonalLeft, diagonalRight));
//         return dp[i][j];
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>>dp(n, vector<int>(n, -1));
//         int ans = 1e9;
//         for (int j = 0; j < n; j++) {
//             ans = min(ans, solve(matrix, 0, j, dp));
//         }
//         return ans;
//     }
// };
// SPACE OPTIMIZATION APPROACH
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int up = i > 0 ? prev[j] : 0;
                    int left = j > 0 ? curr[j - 1] : 0;
                    curr[j] = up + left;
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
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 0));

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == 0 && j == 0) {
//                     dp[i][j] = 1;
//                 } else {
//                     int up = 0;
//                     int left = 0;

//                     if (i > 0)
//                         up = dp[i - 1][j];
//                     if (j > 0)
//                         left = dp[i][j - 1];
//                     dp[i][j] = up + left;
//                 }
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// };

// TOP-DOWN APPROACH
// class Solution {
// public:
//     int solve(int m, int n, vector<vector<int>> dp) {

//         if (n == 0 && m == 0) {
//             return 1;
//         }
//         if (n < 0 || m < 0) {
//             return 0;
//         }
//         if (dp[m][n] != -1) {
//             return dp[m][n];
//         }

//         int up = solve(m - 1, n, dp);
//         int left = solve(m, n - 1, dp);

//         return dp[m][n] = up + left;
//     }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return solve(m - 1, n - 1, dp);
//     }
// };
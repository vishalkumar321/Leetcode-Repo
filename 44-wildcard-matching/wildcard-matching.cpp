// BOTTOM-UP APPROACH
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};

// TOP-DOWN APPROACH :-> Memory Limit Exceeded
// class Solution {
// public:
//     bool solve(int i, int j, string s, string p, vector<vector<char>>& dp) {
//         if (i < 0 && j < 0)
//             return true;
//         if (j < 0 && i >= 0) {
//             return false;
//         }
//         if (i < 0 && j >= 0) {
//             for (int k = 0; k <= j; k++) {
//                 if (p[k] != '*') {
//                     return false;
//                 }
//             }
//             return true;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         if (s[i] == p[j] || p[j] == '?') {
//             return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
//         }

//         if (p[j] == '*') {
//             return dp[i][j] =
//                        solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p,
//                        dp);
//         }

//         return dp[i][j] = false;
//     }

//     bool isMatch(string s, string p) {
//         int n = s.size();
//         int m = p.size();

//         vector<vector<char>> dp(n, vector<char>(m, -1));
//         return solve(n - 1, m - 1, s, p, dp);
//     }
// };
// BOTTOM-UP APPROACH
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return s.size() - dp[n][n];
    }
};

// TOP-DOWN APPROACH
// class Solution {
// public:
//     int solve(int i, int j, const string& s1, const string& s2,
//               vector<vector<int>>& dp) {

//         if (i < 0 || j < 0)
//             return 0;

//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         if (s1[i] == s2[j]) {
//             return dp[i][j] = 1 + solve(i - 1, j - 1, s1, s2, dp);
//         }
//         dp[i][j] =
//             max(solve(i - 1, j, s1, s2, dp), solve(i, j - 1, s1, s2, dp));

//         return dp[i][j];
//     }

//     int longestPalindromeSubseq(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         string t = s;

//         reverse(s.begin(), s.end());
//         return solve(n - 1, n - 1, s, t, dp);
//     }

//     int minInsertions(string s) {
//         return s.size() - longestPalindromeSubseq(s);
//     }
// };
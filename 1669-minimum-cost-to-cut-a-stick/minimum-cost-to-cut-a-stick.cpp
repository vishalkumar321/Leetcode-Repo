// BOTTOM-UP APPROACH
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        for (int len = 1; len <= m-2; len++) { 
            for (int i = 1; i + len - 1 <= m-2; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k <= j; k++) {
                    int cost = cuts[j+1] - cuts[i-1] +
                               (k > i ? dp[i][k-1] : 0) +
                               (k < j ? dp[k+1][j] : 0);
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[1][m-2];
    }
};


// TOP-DOWN APPROACH
// class Solution {
// public:
//     int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
//         if (i > j)
//             return 0;
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         int mini = INT_MAX;
//         for (int index = i; index <= j; index++) {
//             int cost = cuts[j + 1] - cuts[i - 1] +
//                        solve(i, index - 1, cuts, dp) +
//                        solve(index + 1, j, cuts, dp);
//             mini = min(mini, cost);
//         }

//         dp[i][j] = mini;
//         return dp[i][j];
//     }

//     int minCost(int n, vector<int>& cuts) {
//         cuts.push_back(n);
//         cuts.insert(cuts.begin(), 0);
//         int m = cuts.size();
//         sort(cuts.begin(), cuts.end());

//         vector<vector<int>> dp(m, vector<int>(m, -1));
//         return solve(1, m - 2, cuts, dp);
//     }
// };
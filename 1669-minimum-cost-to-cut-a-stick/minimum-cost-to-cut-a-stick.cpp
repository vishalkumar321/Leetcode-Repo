class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int mini = INT_MAX;
        for (int index = i; index <= j; index++) {
            int cost = cuts[j + 1] - cuts[i - 1] +
                       solve(i, index - 1, cuts, dp) +
                       solve(index + 1, j, cuts, dp);
            mini = min(mini, cost);
        }

        dp[i][j] = mini;
        return dp[i][j];
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(m, vector<int>(m, -1));
        return solve(1, m - 2, cuts, dp);
    }
};
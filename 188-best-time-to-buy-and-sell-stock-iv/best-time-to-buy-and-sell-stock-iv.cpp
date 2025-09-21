class Solution {
public:
    int solve(int index, int transNo, int k, vector<int>& prices,
              vector<vector<int>>& dp) {
        int n = prices.size();
        if (index == n || transNo == 2 * k)
            return 0;

        if (dp[index][transNo] != -1) {
            return dp[index][transNo];
        }
        
        if (transNo % 2 == 0) {
            dp[index][transNo] = max(
                -prices[index] + solve(index + 1, transNo + 1, k, prices, dp),
                solve(index + 1, transNo, k, prices, dp));
        } else {
            dp[index][transNo] = max(
                prices[index] + solve(index + 1, transNo + 1, k, prices, dp),
                solve(index + 1, transNo, k, prices, dp));
        }

        return dp[index][transNo];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return solve(0, 0, k, prices, dp);
    }
};
class Solution {
public:
    int solve(int index, int buy, int fee, vector<int>& prices,
              vector<vector<int>>& dp) {
        int n = prices.size();
        if (index == n) {
            return 0;
        }
        if (dp[index][buy] != -1) {
            return dp[index][buy];
        }

        int profit = 0;

        if (buy) {
            profit = max(-prices[index] + solve(index + 1, 0, fee, prices, dp),
                         solve(index + 1, 1, fee, prices, dp));
        } else {
            profit =
                max(prices[index] - fee + solve(index + 1, 1, fee, prices, dp),
                    solve(index + 1, 0, fee, prices, dp));
        }
        dp[index][buy] = profit;
        return dp[index][buy];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, fee, prices, dp);
    }
};
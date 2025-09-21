class Solution {
public:
    int solve(int index, int buy, int cap, vector<int>& prices,
              vector<vector<vector<int>>>& dp) {
        int n = prices.size();

        if (cap == 0)
            return 0;
        if (index == n)
            return 0;
        if (dp[index][buy][cap] != -1) {
            return dp[index][buy][cap];
        }

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + solve(index + 1, 0, cap, prices, dp),
                         solve(index + 1, 1, cap, prices, dp));
        } else {
            profit =
                max(prices[index] + solve(index + 1, 1, cap - 1, prices, dp),
                    solve(index + 1, 0, cap, prices, dp));
        }

        dp[index][buy][cap] = profit;
        return dp[index][buy][cap];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};
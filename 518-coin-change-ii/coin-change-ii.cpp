// TOP-DOWN APPROACH
class Solution {
public:
    int solve(int index, int target, vector<int>& coins,
              vector<vector<int>>& dp) {
        if (index == 0) {
            return (target % coins[0] == 0);
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        int notTake = solve(index - 1, target, coins, dp);
        int take = 0;
        if (coins[index] <= target) {
            take = solve(index, target - coins[index], coins, dp);
        }

        dp[index][target] = take + notTake;
        return dp[index][target];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }
};
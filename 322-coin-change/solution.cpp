// BOTTOM UP APPROACH
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            } else {
                dp[0][i] = 1e9;
            }
        }

        for (int index = 1; index < n; index++) {
            for (int amt = 0; amt <= amount; amt++) {
                int notTake = dp[index - 1][amt];
                int take = 1e9;
                if (coins[index] <= amt) {
                    take = 1 + dp[index][amt - coins[index]];
                }
                dp[index][amt] = min(take, notTake);
            }
        }
        return dp[n - 1][amount] >= 1e9 ? -1 : dp[n - 1][amount];
    }
};



// TOP DOWN APPROACH
// class Solution {
// public:
//     int solve(int index, int amount, vector<int>& coins,
//               vector<vector<int>>& dp) {
//         if (index == 0) {
//             if (amount % coins[0] == 0) {
//                 return amount / coins[0];
//             } else {
//                 return 1e9;
//             }
//         }
//         if (dp[index][amount] != -1) {
//             return dp[index][amount];
//         }

//         int notTake = solve(index - 1, amount, coins, dp);
//         int take = 1e9;
//         if (coins[index] <= amount) {
//             take = 1 + solve(index, amount - coins[index], coins, dp);
//         }
//         dp[index][amount] = min(take, notTake);
//         return dp[index][amount];
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         if(amount==0)return 0;
//         int n = coins.size();
//         vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
//         int ans = solve(n - 1, amount, coins, dp);
//         return ans >= 1e9 ? -1 : ans;
//     }
// };